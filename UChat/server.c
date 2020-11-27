#include <sys/types.h> // константа
#include <sys/socket.h> //  sockе()
#include <stdio.h> // perror()
#include <stdlib.h> // exit()
#include <netinet/in.h> // bind()
#include <unistd.h> // read()
#include <arpa/inet.h> // htons()

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
void Listen(int socketfd, int backlog) {
    int res = listen(socketfd, backlog);
    if (res == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);

    }
}
//обертка
int Accept(int socketfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(socketfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);

    }
    return res;
}

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};//задает адрес по протоколу IPv4. структура вместо 'const struct sockaddr'. инит. 0 - это означает, что с любого IP
    adr.sin_family = AF_INET; //задаем симейство адресов
    adr.sin_port = htons(34543);// порт с которого сервер будет слушать
    Bind(server,(struct sockaddr *) &adr, sizeof adr);   // передает socket  'server' который хотим привязать к адресу '&adr', длина адреса 'sizeof adr'
    Listen(server, 5); // слушаем, количество входящих соединений
    socklen_t adrlen = sizeof adr ;
    int fd = Accept(server, (struct sockaddr *) &adr, &adrlen);// принимаем 1 клиент. Информацию о клиенте записываем в adr
            // поскольку bind уже взял с adr значение, то мы можем использовать adr для пользователя.
            //Функция Accept() вернет файловий дескриптор, через который будет общение с клиентом
    ssize_t nread;
    char buf[256];
    nread = read(fd, buf, 256); //читаем собщение клиента и в буфер, размер буфера 256

    if (nread == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    if (nread == 0) {
        printf("END OF FILE OCCURED\n"); //пользователь не планирует что-то нам передавать, но мы можем передавать сообщение ему.
    }

    write(STDOUT_FILENO, buf, nread); //  сколько мы получили байт
    write(fd, buf, nread);// ответ на сервер. отправили то, что получили.
    // после этого можно закрыть сокет
    //close(fd);
    //close(listen); //закрыть прослушивающий сокет.
    return 0;
}
