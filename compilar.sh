#!/bin/bash
# Como compilar os arquivos em C
# Rodrigo Costa 2018-ABR-29

# 0 - Limpar a tela
clear

# 1 - Compilar o servidor
gcc -Wall servidor.c -o servidor.exe

# 2 - Compilar o cliente
gcc -Wall cliente.c -o cliente.exe

# 3 - Iniciar o servidor
# ./servidor.exe

# 4 - Iniciar o cliente, com o ip do localhost
# ./cliente.exe 127.0.0.1

# 5 - Exibir o resultado da compilação, ZERO deu tudo certo
echo $?

