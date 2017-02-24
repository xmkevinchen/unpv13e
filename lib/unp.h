#ifndef __unp_h
#define __unp_h

/* Miscellaneous constants */
#define MAXLINE     4096
#define BUFFSIZE    8192

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <unistd.h>
#include <time.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTENQ 1024

void err_ret(const char *, ...);
void err_sys(const char *, ...);
void err_quit(const char *, ...);

int Socket(int, int, int);
int Accept(int, struct sockaddr *, socklen_t *);
void Bind(int, const struct sockaddr *, socklen_t);
void Listen(int, int);

#endif
