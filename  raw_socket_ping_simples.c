#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    char packet[4096];
    struct sockaddr_in dest_addr;

    // Criar raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Erro ao criar raw socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço de destino
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "8.8.8.8", &dest_addr.sin_addr);

    // Criar pacote ICMP (simplificado)
    memset(packet, 0, sizeof(packet));
    packet[0] = 8; // Tipo ICMP Echo Request

    // Enviar pacote
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("Erro ao enviar pacote");
        exit(EXIT_FAILURE);
    }

    printf("Pacote ICMP enviado\n");
    close(sockfd);
    return 0;
}
