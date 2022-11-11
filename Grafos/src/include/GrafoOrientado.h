//
// Created by minorro on 5/16/22.
//

#ifndef PAA2_GRAFOORIENTADO_H
#define PAA2_GRAFOORIENTADO_H

#include "Grafo.h"


namespace paa {

    class GrafoOrientado : public Grafo {
    public:
        /**
         * Construtor para um grafo Orientado
         * @param nVert número de vertices do grafo
         */
        explicit GrafoOrientado(int nVert);
        /**
         * Construtor para um Grafo Orientado com arestas inseridas
         * @param nVert número de vértices do grafo
         * @param arestas vetor de tuplas representando arestas <de, para, peso>
         */
        GrafoOrientado(int nVert, const std::vector<std::tuple<int, int, int>>& arestas);

        /**
         * Adiciona uma aresta no Grafo
         * @param de origem da aresta
         * @param para destino da aresta
         * @param peso peso da aresta
         */
        void addAresta(int de, int para, int peso) override;

        /**
         * Executa algoritmo de Bellman-Ford no Grafo
         * @param origem posição do vértice inicial no grafo
         */
        void bellman_ford(int origem) const;

    private:
        /**
         * Faz a relaxação de uma aresta para o algoritmo de Bellman-Ford
         * @param v1 vertice origem
         * @param v2 vertice destino
         * @param peso peso da aresta
         * @param distancias vetor de distancias
         * @param pi vetor de predecessores
         */
        void relax(int v1, int v2, int peso, std::vector<int> &distancias, std::vector<int> &pi) const;
        /**
         * Inicializa a origem para o agloritmo de Bellman-Ford
         * @param v vertice origem
         * @param distancias vetor de distancias
         * @param pi vetor de predecessores
         */
        void inicializa_origem(int v, std::vector<int> &distancias, std::vector<int> &pi) const;
    };

} // paa

#endif //PAA2_GRAFOORIENTADO_H
