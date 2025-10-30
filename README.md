# 💻 Implementação de Sockets em C (TCP, UDP, Raw Ping e HTTP Parser)

Este repositório contém seis exemplos de programas em C que demonstram o uso de *sockets* para diferentes propósitos de rede no Linux, abrangendo os protocolos TCP, UDP, ICMP e HTTP.

## 📁 Estrutura do Projeto

| Arquivo | Descrição | Protocolo Principal |
| :--- | :--- | :--- |
| `servidor_tcp.c` | Implementa um servidor que escuta conexões (porta 8080) e recebe mensagens. | TCP |
| `cliente_tcp.c` | Implementa um cliente que se conecta ao servidor local e envia uma mensagem. | TCP |
| `servidor_udp.c` | Implementa um servidor que aguarda e responde a datagramas (porta 8080). | UDP |
| `cliente_udp.c` | Implementa um cliente que envia um datagrama UDP e espera uma resposta. | UDP |
| `raw_socket_ping_simples.c` | Tenta enviar um pacote ICMP Echo Request usando um *raw socket* (requer `sudo`). | ICMP (Raw) |
| `parser_http.c` | Realiza uma conexão e envia uma requisição HTTP simples para `example.com`. | TCP/HTTP |

## 🛠️ Requisitos

* Sistema Operacional baseado em Linux (ex: Linux Mint, Ubuntu).
* Compilador **GCC** instalado (`sudo apt install build-essential`).
* Acesso à internet para os programas de ping e HTTP.

## ⚙️ Compilação de Todos os Arquivos

Para compilar todos os arquivos-fonte C e gerar os executáveis correspondentes, siga o procedimento abaixo.

### 1. Compilação Manual (Comando a Comando)

Você deve usar o compilador `gcc`, especificando o arquivo fonte e o nome do executável de saída com a opção `-o`.

| Arquivo Fonte | Comando de Compilação | Executável Gerado |
| :--- | :--- | :--- |
| `servidor_tcp.c` | `gcc Servidor_TCP.c -o servidor_tcp` | `servidor_tcp` |
| `cliente_tcp.c` | `gcc Cliente_TCP.c -o cliente_tcp` | `cliente_tcp` |
| `servidor_udp.c` | `gcc servidor_udp.c -o servidor_udp` | `servidor_udp` |
| `cliente_udp.c` | `gcc cliente_udp.c -o cliente_udp` | `cliente_udp` |
| `raw_socket_ping_simples.c` | `gcc Raw_Socket_Ping_Simples.c -o raw_ping` | `raw_ping` |
| `parser_http.c` | `gcc Parser_HTTP.c -o parser_http` | `parser_http` |

### 2. Sugestão: Usando um Script de Compilação Rápida (Exemplo: `build.sh`)

Para compilar todos os arquivos de uma vez, você pode criar um script simples (`build.sh`):

1.  **Crie o arquivo `build.sh`** no mesmo diretório dos seus arquivos `.c`.

    ```bash
    #!/bin/bash

    # Define o compilador
    CC="gcc"

    # Compila os programas TCP
    echo "Compilando Servidor e Cliente TCP..."
    $CC Servidor_TCP.c -o servidor_tcp
    $CC Cliente_TCP.c -o cliente_tcp

    # Compila os programas UDP
    echo "Compilando Servidor e Cliente UDP..."
    $CC servidor_udp.c -o servidor_udp
    $CC cliente_udp.c -o cliente_udp

    # Compila os utilitários de rede
    echo "Compilando Raw Ping e Parser HTTP..."
    $CC Raw_Socket_Ping_Simples.c -o raw_ping
    $CC Parser_HTTP.c -o parser_http

    echo "Compilação concluída. Executáveis gerados!"
    ```

2.  **Dê permissão de execução** e **execute o script**:

    ```bash
    chmod +x build.sh
    ./build.sh
    ```

## 🚀 Como Executar os Programas

Os executáveis serão criados no diretório atual (ex: `./servidor_tcp`).

### 1. Teste TCP (Conexão Orientada)

Abra **dois terminais**.

* **Terminal 1 (Servidor):**
    ```bash
    ./servidor_tcp
    ```
* **Terminal 2 (Cliente):**
    ```bash
    ./cliente_tcp
    ```

### 2. Teste UDP (Não Orientado à Conexão)

Abra **dois terminais**.

* **Terminal 1 (Servidor):**
    ```bash
    ./servidor_udp
    ```
* **Terminal 2 (Cliente):**
    ```bash
    ./cliente_udp
    ```

### 3. Raw Socket Ping

**Atenção:** Requer privilégios de root para usar `SOCK_RAW`.

```bash
sudo ./raw_ping
```

### 4. HTTP Parser

```bash
sudo ./parser_http
```

