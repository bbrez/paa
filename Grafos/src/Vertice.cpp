#include "Vertice.h"
#include <memory>

namespace paa {
/**
 * Adiciona uma aresta no Vertice
 * @param a aresta a ser adicionada
 */
void Vertice::addAresta(const std::shared_ptr<Aresta>& a) { this->arestas.push_back(a); }

/**
 * Adiciona varias arestas no Vertice
 * @param va vetor de arestas a ser adicionados
 */
void Vertice::addArestas(const std::vector<std::shared_ptr<Aresta>>& va) {
    this->arestas.insert(this->arestas.end(), va.begin(), va.end());
}

/**
 * retorna uma aresta do Vertice
 * @param pos posição da aresta
 * @return aresta
 */
std::shared_ptr<Aresta> Vertice::getAresta(int pos) { return this->arestas.at(pos); }

/**
 * retorna o numero de arestas
 * @return numero de arestas
 */
unsigned int Vertice::numArestas() const { return this->arestas.size(); }

/**
 * @brief Acessa uma aresta o vertice
 * @param idx numero da aresta
 * @return std::shared_ptr<Aresta> 
 */
std::shared_ptr<Aresta> Vertice::operator[](std::size_t idx) { return this->arestas[idx]; }

/**
 * @brief Acessa uma aresta o vertice
 * @param idx numero da aresta
 * @return std::shared_ptr<Aresta> 
 */
const std::shared_ptr<Aresta> Vertice::operator[](std::size_t idx) const { return this->arestas[idx]; }

/**
 * @brief Faz uma nova Aresta com peso 1 entre dois Vertices
 * @param v 
 * @return std::shared_ptr<Aresta> 
 */
std::shared_ptr<Aresta> Vertice::operator-(std::shared_ptr<Vertice> v) {
    auto a = std::make_shared<Aresta>(new Aresta(v, 1));
    this->addAresta(a);
    return a;
}
} // namespace paa