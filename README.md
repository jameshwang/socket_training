### Network Socket Training

As a learning exercise for Unix sockets, @groundwater challanged me to write a simple tcp/ip server that output a response.

I first did a quick mock up in node to make sure I was using the `nc` unix tool correctly.  Then I create went through the exercise of creating a C program to better understand what node and other language/libraries were doing with the tools Unix the operating system provided.

### Testing on your own

##### Just testing C file

Download the `hello.c` file and run `make hello`.  This will then create a binary file called `hello`. This binary will create a local server running on port `9500` which you can execute via:

```bash
./hello
```

to kill the server, just use `Ctrl-C`

Then on another terminal connect to this simple server using:
```bash
nc localhost 9500
```

You should see a response back from the server saying:
```bash
Hello World!
```
---
##### Just testing the JS file

Download the `hello.js` file and install `node`.  Then run the server by:
```bash
node hello.js
```

Then similary to the example in the C testing, go to another terminal and run:
```bash
nc localhost 9500
```
