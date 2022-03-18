# Trabalho de Projeto e Análise de Algoritmos
## Compactador de arquivos utilizando Código de Huffman
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

---
### Instruções de Utilização

* Para comprimir arquivos de texto
    1. Selecionar o tipo de compressão mais adequado para o arquivo a ser comprimido (palavra ou caractere)
    2. Escrever o nome do arquivo de entrada (ex. `texto.txt`)
    3. Escrever um nome para o arquivo de saida (ex. `texto.bin`)
    4. O arquivo está comprimido


* Para comprimir arquivos binários
    1. Converter o arquivo para texto usando uma utilidade adequada (ex. `xxd` em sistemas linux)
    2. Realizar a conversão como arquivo de texto em modo caractere


* Para descomprimir qualquer arquivo
    1. Selecionar a opção de descompressão no menu
    2. Escrever o nome do arquivo de entrada (ex. `texto.bin`)
    3. Escrever um nome para o arquivo de saida (ex. `texto2.txt`)
    4. Arquivos binários que foram convertidos para texto devem ser convertidos para o formato original
