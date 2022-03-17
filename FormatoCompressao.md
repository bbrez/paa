# Formato do arquivo comprimido

## Cabeçalho

`data_offset` --> deslocamento do inicio da seção de dados do arquivo [unsigned int, 4 bytes]

`last_byte_size` --> quantos bits significativos estão no ultimo byte do arquivo [unsigned char, 1 byte]

`translation_dict` --> dicionario para decodificação do arquivo [tam|palavra|tam|bin]

* tam --> comprimento da string que segue, 1 byte
* palavra --> texto da palavra no arquivo original, {tam} bytes
* bin --> codigo binario da que representa a palavra no arquivo comprimido, {tam} bytes

## Dados

Começa a partir do byte de numero demarcado por `data_offset`

Os dados são escritos bit a bit utilizando o `translation_dict`

Para leitura deve-se ler os bits até formar uma cadeia que se encaixa em uma das definições do `translation_dict`, pelo fato do código ser livre de prefixo, o primeiro código encontrado é o correto