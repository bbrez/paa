# Formato do arquivo comprimido

## Cabeçalho

`data_offset` --> deslocamento do inicio da seção de dados do arquivo

`mode` --> modo de leitura do arquivo original (0 para caractere e 1 para palavra)

`translation_dict` --> dicionario para decodificação do arquivo (tam|palavra|tam|bin)

## Dados

Começa a partir do byte de numero demarcado por `data_offset`

Os dados são escritos bit a bit utilizando o `translation_dict`

Para leitura deve-se ler os bits até formar uma cadeia que se encaixa em uma das definições do `translation_dict`, pelo fato do código ser livre de prefixo, o primeiro código encontrado é o correto