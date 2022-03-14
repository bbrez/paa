import random

palavras = ['peixe', 'porta', 'janela', 'carro', 'sorte', '\n']

texto = list()
for i in range(1, 20):
    texto.append(random.choice(palavras))

texto = ' '.join(texto)

with open('test_file.txt', 'w') as file:
    file.write(texto)