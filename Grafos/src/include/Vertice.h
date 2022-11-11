#ifndef PAA_VERTICE_H
#define PAA_VERTICE_H

#include <vector>
#include <memory>

#include "Aresta.h"

namespace paa {

class Vertice {
public:

    Vertice() = default;
    /**
     * Adiciona uma aresta no Vertice
     * @param a aresta a ser adicionada
     */
    void addAresta(const std::shared_ptr<Aresta>& a);
    /**
     * Adiciona varias arestas no Vertice
     * @param va vetor de arestas a ser adicionados
     */
    void addArestas(const std::vector<std::shared_ptr<Aresta>>& va);

    /**
     * retorna o numero de arestas
     * @return numero de arestas
     */
    unsigned int numArestas() const;

    /**
     * retorna uma aresta do Vertice
     * @param pos posição da aresta
     * @return aresta
     */
    std::shared_ptr<Aresta> getAresta(int pos);

    /**
     * @brief Acessa uma aresta o vertice
     * @param idx numero da aresta
     * @return std::shared_ptr<Aresta> 
     */
    std::shared_ptr<Aresta> operator[](std::size_t idx);
    /**
     * @brief Acessa uma aresta o vertice
     * @param idx numero da aresta
     * @return std::shared_ptr<Aresta> 
     */
    const std::shared_ptr<Aresta> operator[](std::size_t idx) const;

    /**
     * @brief Faz uma nova Aresta com peso 1 entre dois Vertices
     * @param v 
     * @return std::shared_ptr<Aresta> 
     */
    std::shared_ptr<Aresta> operator-(std::shared_ptr<Vertice> v);

private:

    std::vector<std::shared_ptr<Aresta>> arestas;
};

} // namespace paa

#endif //PAA_VERTICE_H
