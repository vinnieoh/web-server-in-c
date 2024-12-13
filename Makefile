# Variáveis
CC = gcc                 # Compilador
CFLAGS = -Wall -Wextra   # Flags de compilação
TARGET = server          # Nome do executável
SRC = main.c             # Arquivos fonte
OBJ = $(SRC:.c=.o)       # Arquivos objeto

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Regra para compilar arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpeza de arquivos temporários e executáveis
clean:
	rm -f $(TARGET) $(OBJ)

# Regra para recompilar do zero
rebuild: clean all

# Regra de ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make         - Compila o programa"
	@echo "  make run     - Compila e executa o programa"
	@echo "  make clean   - Remove arquivos gerados (executáveis e objetos)"
	@echo "  make rebuild - Recompila do zero"
	@echo "  make help    - Exibe esta mensagem de ajuda"
