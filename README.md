# Servidor Web Simples em C

Este projeto foi desenvolvido com o objetivo de revisão e aprendizado sobre os conceitos fundamentais de redes e programação em C. Ele implementa um servidor web básico que escuta conexões HTTP na porta 8080 e responde com uma página HTML simples. O foco é proporcionar uma base prática para compreender como funcionam os sockets, o protocolo HTTP e a estrutura de um servidor web.

## Funcionalidades

- Escuta conexões em uma porta definida (8080 por padrão).

- Responde a requisições HTTP com uma mensagem "Hello, World!" em HTML.

- Utiliza sockets para comunicação cliente-servidor.

- Estruturado com funções modulares e uma struct para organização do servidor.

## Requisitos

- Compilador C (como gcc)

- Sistema operacional Linux ou compatível com POSIX

## Como usar

### 1. Clonar o repositório

```bash
git@github.com:vinnieoh/web-server-in-c.git
cd web-server-in-c
```

### 2. Compilar o código
Utilize o gcc para compilar o código fonte:

```bash
gcc -o webserver webserver.c
```

Ou use o Makefile incluso:

```bash
make
```

### 3. Executar o servidor

Inicie o servidor com:

```bash
./webserver
```

Ou, usando o Makefile:

```bash
make run
```

O servidor estará escutando em http://localhost:8080.

### 4. Limpar arquivos gerados

Para remover os arquivos compilados, utilize:
  
```bash 
make clean
```

### 5. Recompilar do zero

Para limpar e recompilar tudo:

```bash
make rebuild
```

### 6. Obter ajuda

Para exibir os comandos disponíveis no Makefile:
  
```bash 
make help
```

### 7. Testar o servidor

Abra um navegador e acesse:

``` 
http://localhost:8080
```

Você verá a seguinte resposta:
  
```html
<html>
  <body>
    <h1>Hello, World!</h1>
    <p>Servidor Hello World!</p>
  </body>
</html>
```

## Estrutura do Código

1. initialize_server(int port)

 - Inicializa o servidor configurando o socket, bind, e escuta.

2. handle_client(int client_fd)

 - Processa a requisição de um cliente e responde com uma página HTML.

3. run_server(WebServer *server)

 - Gerencia o loop principal do servidor, aceitando conexões e delegando ao handler.

4. cleanup_server(WebServer *server)

 - Encerra o servidor e libera recursos.
 
## Melhorias Futuras
 
- [ ] Suporte a múltiplas conexões simultâneas utilizando threads.
 
- [ ] Adição de suporte a HTTPS com TLS/SSL.
 
- [ ] Parsing de requisições HTTP para lidar com diferentes rotas.

## Licença

Este projeto está licenciado sob a MIT License.