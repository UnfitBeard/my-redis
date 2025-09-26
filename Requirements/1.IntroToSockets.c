# include <stdio.h>

/**
 * SERVER SIDE
 * fd is an integers that refers to sth FIle Descriptor
 *  fd = socket()
bind(fd, address)
listen(fd)
while True:
    conn_fd = accept(fd)
    // do sth with conn
    close(conn)

 * CLIENT SIDE
 fd = socket()
 connect(fd, address)
 do sth with fd
 close(fd)
 */
