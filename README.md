# Trabalho de Projeto e Análise de Algoritmos
## Compactador de arquivos utilizando Código de Huffman
---
### Instruções de Compilação
**[Atenção] O programa foi desenvolvido utilizando o padrão C++20, testado nos compiladores gcc(versão 11.2) e clang(13.0)**
* Utilizando CMake (**Recomendado**) [configuração gerada para CMake 3.21]
    1. Criar um diretório de compilação na pasta `paa` (ex. `paa\build`)
    1. Entrar no diretório criado
    1. Executar os comandos `cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release ..` e `cmake --build .`
* Compilação Manual
    1. Criar um diretório de compilação na pasta `paa` (ex. `paa\build`)
    1. Entrar no diretório criado
    1. Executar o comando `g++ --std=gnu++20 -O2 ..\src\*.cpp -I ..\src\include\ -o paa`
    1. Opcionalmente adicionar os argumentos `-Werror -Wall -Wextra --pedantic` para verificação de warnings
* Com o programa compilado, ele pode ser executado com o arquivo `paa.exe` gerado na pasta de compilação
