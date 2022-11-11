//
// Created by minorro on 5/16/22.
//

#include "Aresta.h"

#include <utility>
#include <iostream>

namespace paa {

    /**
     * Get peso da aresta
     * @return peso da aresta
     */
    int Aresta::getPeso() const {
        return this->peso;
    }

    /**
    * Retorna ponteiro do destino da aresta
    * @return ponteiro do destino da aresta
    */
    std::shared_ptr<Vertice> Aresta::getDestino() const {
        return this->destino;
    }

    /**
     * Construtor de uma aresta
     * @param destino destino da aresta
     * @param peso peso da aresta
     */
    Aresta::Aresta(std::shared_ptr<Vertice> destino, int peso) {
        this->destino = std::move(destino);
        this->peso = peso;
    }
}