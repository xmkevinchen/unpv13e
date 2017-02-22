#include "unp.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int     listenfd, connfd;
  struct  sockaddr_in servaddr;
  char    buff[MAXLINE];
  time_t  ticks;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family       = AF_INET;
  servaddr.sin_addr.s_addr  = htonl(INADDR_ANY);
  servaddr.sin_port         = htons(10003);

  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  listen(listenfd, LISTENQ);

  for (;;) {
    connfd = accept(listenfd, NULL, NULL);
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
    write(connfd, buff, strlen(buff));

    close(connfd);
  }

  return 0;
}
