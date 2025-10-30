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
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // Criar socket UDP
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço do servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Vincular socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Erro no bind");
        exit(EXIT_FAILURE);
    }

    // Receber mensagem
    int n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_addr, &addr_len);
    buffer[n] = '\0';
    printf("Mensagem do cliente: %s\n", buffer);

    // Enviar resposta
    char *response = "Mensagem recebida!";
    sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, addr_len);

    close(sockfd);
    return 0;
}
