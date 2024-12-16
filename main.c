#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define QUEUE_SIZE 10

typedef struct {
    int server_fd;                // File descriptor do socket do servidor
    struct sockaddr_in address;   // Estrutura de endereço
    int addr_len;                 // Tamanho do endereço
} WebServer;

WebServer initialize_server(int port) {
    WebServer server;

    // Cria o socket
    server.server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.server_fd == 0) {
        perror("Falha ao criar o socket");
        exit(EXIT_FAILURE);
    }

    // Configuração do endereço
    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = INADDR_ANY;
    server.address.sin_port = htons(port);
    server.addr_len = sizeof(server.address);

    // Bind (associa o socket ao endereço e porta)
    if (bind(server.server_fd, (struct sockaddr *)&server.address, sizeof(server.address)) < 0) {
        perror("Falha no bind");
        close(server.server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen (escuta por conexões)
    if (listen(server.server_fd, QUEUE_SIZE) < 0) {
        perror("Falha ao escutar");
        close(server.server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor rodando em http://localhost:%d\n", port);
    return server;
}

// Função para processar uma requisição do cliente
void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE] = {0};

    // Lê a requisição HTTP do cliente
    read(client_fd, buffer, BUFFER_SIZE);
    printf("Requisição recebida:\n%s\n", buffer);

    // Resposta HTTP simples
    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n\r\n"
        "<html><body><h1>Hello, World!</h1><p>Servidor Hello World!</p></body></html>";

    // Envia a resposta ao cliente
    write(client_fd, response, strlen(response));

    // Fecha a conexão com o cliente
    close(client_fd);
}

// Função principal do servidor para aceitar conexões
void run_server(WebServer *server) {
    while (1) {
        int client_fd = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addr_len);
        if (client_fd < 0) {
            perror("Falha ao aceitar conexão");
            continue;
        }

        handle_client(client_fd);
    }
}

// Função para encerrar o servidor com limpeza de recursos
void cleanup_server(WebServer *server) {
    close(server->server_fd);
    printf("Servidor encerrado.\n");
}

int main() {
    WebServer server = initialize_server(PORT);
    run_server(&server);
    cleanup_server(&server);
    return 0;
}
