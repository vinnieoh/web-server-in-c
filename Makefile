# Variáveis
CC = gcc                 # Compilador
CFLAGS = -Wall -Wextra   # Flags de compilação
TARGET = server          # Nome do executável
SRC = main.c             # Arquivos fonte

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpeza de arquivos temporários e executáveis
clean:
	rm -f $(TARGET)

# Regra para recompilar do zero
rebuild: clean all
