#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    char response[4096];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "93.184.216.34", &server.sin_addr); // IP de example.com

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Erro na conexão");
        exit(EXIT_FAILURE);
    }

    // Enviar requisição HTTP
    send(sock, request, strlen(request), 0);

    // Receber resposta
    int n = recv(sock, response, sizeof(response) - 1, 0);
    response[n] = '\0';

    // Parsear HTML (exemplo simples: exibir resposta)
    printf("Resposta:\n%s\n", response);

    close(sock);
    return 0;
}
