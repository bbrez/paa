//
// Created by minorro on 5/16/22.
//

#include "Vertice.h"

namespace paa {

    /**
     * Adiciona uma aresta no Vertice
     * @param a aresta a ser adicionada
     */
    void Vertice::addAresta(const std::shared_ptr<Aresta>& a) {
        this->arestas.push_back(a);
    }

    /**
     * Adiciona varias arestas no Vertice
     * @param va vetor de arestas a ser adicionados
     */
    void Vertice::addArestas(const std::vector<std::shared_ptr<Aresta>> &va) {
        this->arestas.insert(this->arestas.end(), va.begin(), va.end());
    }

    /**
     * retorna uma aresta do Vertice
     * @param pos posição da aresta
     * @return aresta
     */
    std::shared_ptr<Aresta> Vertice::getAresta(int pos) {
        return this->arestas.at(pos);
    }

    /**
     * retorna o numero de arestas
     * @return numero de arestas
     */
    unsigned int Vertice::numArestas() const {
        return this->arestas.size();
    }

}