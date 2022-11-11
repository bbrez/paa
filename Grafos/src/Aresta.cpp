#include <Aresta.h>

#include <utility>
#include <iostream>

namespace paa {
/**
 * @brief Constroi uma nova aresta
 * @param destino destino da aresta
 * @param peso peso da aresta
 */
Aresta::Aresta(std::shared_ptr<Vertice> destino, int peso) {
    this->destino = std::move(destino);
    this->peso = peso;
}

/**
 * @brief Retorna o ponteiro do destino da aresta
 * @return std::shared_ptr<Vertice> destino da aresta
 */
std::shared_ptr<Vertice> Aresta::getDestino() const { return this->destino; }

/*
 * @brief Retorna o peso da aresta
 * @return int 
 */
int Aresta::getPeso() const { return this->peso; }

/**
 * @brief Muda o peso de uma aresta e retorna o novo valor
 * @param novo_peso
 * @return int
 */
int Aresta::operator[](int novo_peso) {
    this->peso = novo_peso;
    return novo_peso;
}
} // namespace paa
