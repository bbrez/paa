#ifndef PAA2_ARESTA_H
#define PAA2_ARESTA_H


#include <memory>


namespace paa {
    class Vertice;

    class Aresta {
    public:
        /**
         * Construtor de uma aresta
         * @param destino destino da aresta
         * @param peso peso da aresta
         */
        Aresta(std::shared_ptr<Vertice> destino, int peso);

        /**
         * Retorna ponteiro do destino da aresta
         * @return ponteiro do destino da aresta
         */
        std::shared_ptr<Vertice> getDestino() const;

        /**
         * Get peso da aresta
         * @return peso da aresta
         */
        int getPeso() const;

    private:
        std::shared_ptr<Vertice> destino;
        int peso;
    };

}

#endif //PAA2_ARESTA_H
