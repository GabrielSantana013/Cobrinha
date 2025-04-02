# Nome do executável
TARGET = nibbles.exe

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Ifunctions

# Diretórios
SRC_DIR = src
FUNC_DIR = functions
VIEW_DIR = view

# Arquivos fonte
C_SOURCES = $(wildcard $(SRC_DIR)/*.c $(FUNC_DIR)/*.c $(VIEW_DIR)/*.c)
H_SOURCES = $(wildcard $(FUNC_DIR)/*.h $(VIEW_DIR)/*.h)

# Variável para limpeza
RM = rm -f

# Regra principal: compilar o programa
$(TARGET): $(C_SOURCES) $(H_SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_SOURCES) -lncurses

# Regra para limpar os arquivos gerados
clean:
	@$(RM) $(TARGET)

.PHONY: all clean
