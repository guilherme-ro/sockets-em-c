#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Olá, servidor!";
    char buffer[1024] = {0};

    // Criar socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converter endereço IP
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Endereço inválido");
        exit(EXIT_FAILURE);
    }

    // Conectar ao servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erro na conexão");
        exit(EXIT_FAILURE);
    }

    // Enviar mensagem
    send(sock, message, strlen(message), 0);
    printf("Mensagem enviada\n");

    // Receber resposta
    read(sock, buffer, 1024);
    printf("Resposta do servidor: %s\n", buffer);

    close(sock);
    return 0;
}
