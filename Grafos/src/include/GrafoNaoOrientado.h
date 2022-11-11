//
// Created by minorro on 5/16/22.
//

#ifndef PAA2_GRAFONAOORIENTADO_H
#define PAA2_GRAFONAOORIENTADO_H

#include "Grafo.h"

namespace paa {

    class GrafoNaoOrientado : public Grafo {
    public:
        /**
         * Construtor para um Grafo Não Orientado
         * @param nVert número de vertices do grafo
         */
        explicit GrafoNaoOrientado(int nVert);
        /**
         * Construtor para um Grafo Não Orientado com arestas inseridas
         * @param nVert número de vértices do grafo
         * @param arestas vetor de tuplas representando arestas <de, para, peso>
         */
        GrafoNaoOrientado(int nVert, const std::vector<std::tuple<int, int, int>>& arestas);

        /**
         * Adiciona uma aresta no Grafo da origem para o destino e ao contrario
         * @param de origem da aresta
         * @param para destino da aresta
         * @param peso peso da aresta
         */
        void addAresta(int de, int para, int peso) override;
    };

} // paa

#endif //PAA2_GRAFONAOORIENTADO_H
