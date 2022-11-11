//
// Created by minorro on 5/16/22.
//

#ifndef PAA2_VERTICE_H
#define PAA2_VERTICE_H

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
    private:
        std::vector<std::shared_ptr<Aresta>> arestas;
    };

}

#endif //PAA2_VERTICE_H
