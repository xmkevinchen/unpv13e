#include "unp.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int     listenfd, connfd;
  struct  sockaddr_in servaddr;
  char    buff[MAXLINE];
  time_t  ticks;

  listenfd = Socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family       = AF_INET;
  servaddr.sin_addr.s_addr  = htonl(INADDR_ANY);
  servaddr.sin_port         = htons(10013);

  Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  Listen(listenfd, LISTENQ);

  for (;;) {
    connfd = Accept(listenfd, NULL, NULL);
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
    if (write(connfd, buff, strlen(buff)) != strlen(buff)) {
        err_sys("write error");
    }

    close(connfd);
  }

  return 0;
}
