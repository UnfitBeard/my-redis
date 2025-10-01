# my-redis

> I like to call it gredis as in georges redis

> A simple custom Redis implementation

## 🛠️ Compilation

To compile the server and client programs, use the following commands:

```bash
g++ -Wall -Wextra -O2 -g 03_server.cpp -o server
```

```bash
g++ -Wall -Wextra -O2 -g 03_client.cpp -o client
```

## 🚀 Running the Programs

1. Start the **server** in one terminal window:

   ```bash
   ./server
   ```

2. Then run the **client** in another terminal window:

   ```bash
   ./client
   ```

## 📝 Expected Output

You should see something like the following:

**Server terminal:**

```
$ ./server
client says: hello
```

**Client terminal:**

```
$ ./client
server says: world
```
