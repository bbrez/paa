//
// Created by minorro on 5/16/22.
//

#include "GrafoNaoOrientado.h"

namespace paa {
    /**
     * Construtor para um Grafo Não Orientado
     * @param nVert número de vertices do grafo
     */
    GrafoNaoOrientado::GrafoNaoOrientado(int nVert) : Grafo(nVert) {}
    /**
     * Construtor para um Grafo Não Orientado com arestas inseridas
     * @param nVert número de vértices do grafo
     * @param arestas vetor de tuplas representando arestas <de, para, peso>
     */
    GrafoNaoOrientado::GrafoNaoOrientado(int nVert, const std::vector<std::tuple<int, int, int>>& arestas) : Grafo(nVert) {
        for(const auto &a: arestas){
            auto [de, para, peso] = a;
            this->addAresta(de, para, peso);
        }
    }

    /**
     * Adiciona uma aresta no Grafo da origem para o destino e ao contrario
     * @param de origem da aresta
     * @param para destino da aresta
     * @param peso peso da aresta
     */
    void GrafoNaoOrientado::addAresta(int de, int para, int peso) {
        this->getVertice(de)->addAresta(std::make_shared<Aresta>(this->getVertice(para), peso));
        this->getVertice(para)->addAresta(std::make_shared<Aresta>(this->getVertice(de), peso));
    }
} // paa