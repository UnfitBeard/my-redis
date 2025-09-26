#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void do_something(int connfd)
{
    char rbuf[64] = {};
    ssize_t n = read(connfd, rbuf, sizeof(rbuf) - 1);
    if (n < 0)
    {
        perror("read");
        return;
    }

    printf("client says: %s\n", rbuf);

    char wbuf[] = "world";
    write(connfd, wbuf, strlen(wbuf));
}

void die(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    /*
    SO_REUSEADDR - restart a TCP server quckly without waiting for old conn to fully terminate
    */

    struct sockaddr_in addr = {};

    addr.sin_family = AF_INET;
    addr.sin_port = ntohs(1234);     /*ntohs function returns the value in host byte order*/
    addr.sin_addr.s_addr = ntohl(0); // wildcard address 0.0.0.0 /*ntohl() function translates an unsigned long integer from network byte order to host byte order.*/
    int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr));
    if (rv)
    {
        die("bind()");
    }

    rv = listen(fd, SOMAXCONN);

    if (rv)
    {
        die("bind");
    }

    // loop for each conn and do sth
    while (true)
    {
        // accept
        struct sockaddr_in client_addr = {};
        socklen_t socklen = sizeof(client_addr);
        int connfd = accept(fd, (struct sockaddr *)&client_addr, &socklen);
        if (connfd < 0)
        {
            continue; // error
        }
        do_something(connfd);
        close(connfd);
    }
    return 0;
}