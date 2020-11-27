#include <sys/types.h> // константа
#include <sys/socket.h> //  sockе()
#include <stdio.h> // perror()
#include <stdlib.h> // exit()
#include <netinet/in.h> // bind()
#include <arpa/inet.h> // htons()
#include <unistd.h> // read()
#include "../erproc.h"

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};//задает адрес по протоколу IPv4. структура вместо 'const struct sockaddr'. инит. 0 - это означает, что с любого IP
    adr.sin_family = AF_INET; //задаем симейство адресов
    adr.sin_port = htons(34543);// порт с которого сервер будет слушать
    Bind(server,(struct sockaddr *) &adr, sizeof adr);   // передает socket  'serve r' который хотим привязать к адресу '&adr', длина адреса 'sizeof adr'
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

    sleep(1);

    close(fd);
    close(server); //закрыть прослушивающий сокет.
    return 0;
}
