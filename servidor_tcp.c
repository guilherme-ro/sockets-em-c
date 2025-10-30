#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    char buffer[1024] = {0};
    
    // Criar socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço do servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Vincular socket ao endereço
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Erro no bind");
        exit(EXIT_FAILURE);
    }

    // Escutar conexões
    if (listen(server_fd, 3) < 0) {
        perror("Erro no listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexões na porta %d...\n", PORT);

    // Aceitar conexão
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);
    if (new_socket < 0) {
        perror("Erro no accept");
        exit(EXIT_FAILURE);
    }

    // Ler mensagem do cliente
    read(new_socket, buffer, 1024);
    printf("Mensagem do cliente: %s\n", buffer);

    // Enviar resposta
    char *response = "Mensagem recebida!";
    send(new_socket, response, strlen(response), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}
