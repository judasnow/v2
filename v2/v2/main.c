#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MAXLINE 1024


int
open_clientfd(char *hostname, int port) {
    
    int clientfd;
    
    struct hostent *hp;
    struct sockaddr_in serveraddr;
    
    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    
    if ((hp = gethostbyname(hostname)) == NULL) {
        return -2;
    }
    
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *) hp->h_addr,
          (char *) &serveraddr.sin_addr.s_addr, hp->h_length);
    
    serveraddr.sin_port = htons(port);
    
    if (connect(clientfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        return -1;
    }
    
    return clientfd;
}


int
main(int argc, char **argv) {
    
    int clientfd, port;
    char *host, buf[MAXLINE];
    
    if (argc != 3) {
        printf("usage: %s <host> <port>\n", argv[0]);
    }
    
    host = argv[1];
    port = atoi(argv[2]);
    
    return 0;
}


