import random

palavras = ['peixe', 'porta', 'gato', 'melancia', 'banana', '\n']

texto = list()
for i in range(1, 5000):
    texto.append(random.choice(palavras))

texto = ' '.join(texto)

with open('test_file.txt', 'w') as file:
    file.write(texto)
