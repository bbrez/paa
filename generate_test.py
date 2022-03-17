import random

palavras = ['peixe', 'porta', 'gato', 'melancia', 'banana', '\n']

tam = int(input('Tamanho do arquivo em kb'))

texto = list()
for i in range(1, 50000):
    texto.append(random.choice(palavras))

texto = ' '.join(texto)

with open('test_file.txt', 'w') as file:
    file.write(texto)
