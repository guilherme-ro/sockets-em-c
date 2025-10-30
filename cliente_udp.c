#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    char buffer[1024];
    char *message = "Olá, servidor UDP!";
    struct sockaddr_in serv_addr;

    // Criar socket UDP
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço do servidor
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Enviar mensagem
    sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Mensagem enviada\n");

    // Receber resposta
    int addr_len = sizeof(serv_addr);
    int n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&serv_addr, &addr_len);
    buffer[n] = '\0';
    printf("Resposta do servidor: %s\n", buffer);

    close(sockfd);
    return 0;
}
