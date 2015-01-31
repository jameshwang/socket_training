#include <sys/socket.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int setupSocket(int port, char address[]);
int listenAndWriteToSocket(int listenfd);

int main(int argc, char const *argv[]) {
  int listenfd = setupSocket(9500, "127.0.0.1");

  listenAndWriteToSocket(listenfd);

  return 0;
}

int setupSocket(int port, char address[]) {
  int listenfd = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in serv_addr;

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = PF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(address);
  serv_addr.sin_port = htons(port);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 1);

  return listenfd;
}

int listenAndWriteToSocket(int listenfd) {
  char greeting[20] = "Hello World!\n";

  int responsefd = 0;

  while(1) {
    responsefd = accept(listenfd, (struct sockaddr*)NULL, NULL);

    write(responsefd, greeting, strlen(greeting));

    close(responsefd);

    printf("I just printed out: %s", greeting);
  }
}
