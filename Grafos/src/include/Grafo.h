//
// Created by minorro on 5/16/22.
//

#ifndef PAA2_GRAFO_H
#define PAA2_GRAFO_H

#include <vector>

#include "Vertice.h"
#include "util.h"

namespace paa {
    class Grafo {
    public:
        /**
        * Construtor Grafo
        * @param nVert numero de vertices no grafo
        */
        explicit Grafo(int nVert);

        virtual ~Grafo() = default;

        /**
        * Adiciona um vertice no grafo
        * @param v ponteiro do vertice a ser adicionado
        */
        void addVertice(const std::shared_ptr<Vertice>& v);
        /**
         * Adiciona multiplos vertices no grafo
         * @param vv vetor de vertices a serem adicionados.
         */
        void addVertices(const std::vector<std::shared_ptr<Vertice>>& vv);
        /**
         * Adiciona uma aresta entre dois vertices
         * @param de vertice origem da aresta
         * @param para vertice destino da aresta
         * @param peso peso da aresta a ser criada
         */
        virtual void addAresta(int de, int para, int peso) = 0;

        /**
         * Pega um vertice na posição pos
         * @param pos posição do vertice
         * @return vertice escolhido
         */
        std::shared_ptr<Vertice> getVertice(int pos) const;
        /**
         * Encontra a posição de um vertice no vetor de vertices
         * @param v vertice a ser encontrado
         * @return posição
         */
        unsigned int posVertice(const std::shared_ptr<Vertice>& v) const;

        /**
         * Printa o grafo no terminal
         */
        void printGrafo() const;

        /**
          * algoritmo de busca em profundidade
          * @param inicial vertice para iniciar a busca
          */
        void busca_profundidade(int inicial) const;
        /**
          * Algoritmo de busca em largura no grafo
          * @param inicial posição do vertice para iniciar a busca
          */
        void busca_largura(int inicial) const;

        void kruskal() const;
        void prim(int inicial) const;

    protected:
        std::vector<std::shared_ptr<Vertice>> vertices;

        /**
          * Visita um vertice na busca em profundidade
          * @param v_atual posição do vertice atual
          * @param estado estado de visita de cada vertice
          */
        void visita_busca_profundidade(unsigned int v_atual, std::vector<Cor> &estado) const;
        /**
          * Visita os vertices na busca em largura
          * @param v_atual vertice inicial
          * @param estado estado de visita de cada vertice
          */
        void visita_busca_largura(unsigned int v_atual, std::vector<Cor> &estado) const;
    };
}

#endif //PAA2_GRAFO_H
