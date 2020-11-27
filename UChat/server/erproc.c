#include "erproc.h"
#include <sys/types.h>
#include <sys/socket.h> //  sockе()
#include <stdio.h> // perror()
#include <stdlib.h> // exit()
#include <unistd.h> // read()
#include <arpa/inet.h>

// Обертка
int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

//обертка для оригинальной функции bind()
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen); //вызов
    if (res == -1) {
        perror("bind failed"); //нет привязки
        exit(EXIT_FAILURE);
    }
}
//обертка
void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    if (res == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);

    }
}
//обертка
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);

    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0 ) {
        printf("inet_pton failed: src does not containe a character"
               "string representing a valid network address in the specified"
               "address family\n");
        exit(EXIT_FAILURE);
    }

    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}