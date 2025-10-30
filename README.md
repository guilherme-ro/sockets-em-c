# 💻 Implementação de Sockets em C (Servidor, Cliente, Raw Ping e HTTP Parser)

Este repositório contém quatro exemplos de programas em C que demonstram o uso de *sockets* para diferentes propósitos de rede no Linux.

## 📁 Estrutura do Projeto

| Arquivo | Descrição | Protocolo Principal |
| :--- | :--- | :--- |
| `servidor_tcp.c` | Implementa um servidor que escuta conexões e recebe mensagens. | TCP |
| `cliente_tcp.c` | Implementa um cliente que se conecta ao servidor e envia uma mensagem. | TCP |
| `raw_socket_ping_simples.c` | Tenta enviar um pacote ICMP Echo Request usando um *raw socket*. | ICMP (Raw) |
| `parser_http.c` | Realiza uma conexão e envia uma requisição HTTP simples para `example.com`. | TCP/HTTP |

## 🚀 Como Compilar e Executar

Para compilar e executar estes programas, você precisará ter o **GCC** (GNU Compiler Collection) instalado no seu sistema Linux (como o Mint).

### 1. Servidor e Cliente TCP

Estes dois programas trabalham em conjunto. O servidor deve ser iniciado primeiro.

#### **Passo 1: Compilação**

```bash
gcc servidor_tcp.c -o servidor_tcp
gcc cliente_tcp.c -o cliente_tcp
