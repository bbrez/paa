#ifndef PAA_ARESTA_H
#define PAA_ARESTA_H

#include <memory>

namespace paa {
class Vertice;

class Aresta {
public:

    /**
     * @brief Constroi uma nova aresta
     * @param destino destino da aresta
     * @param peso peso da aresta
     */
    Aresta(std::shared_ptr<Vertice> destino, int peso);

    /**
     * @brief Retorna o ponteiro do destino da aresta
     * @return std::shared_ptr<Vertice> destino da aresta
     */
    std::shared_ptr<Vertice> getDestino() const;

    /*
     * @brief Retorna o peso da aresta
     * @return int 
     */
    int getPeso() const;

    /**
     * @brief Muda o peso de uma aresta e retorna o novo valor
     * @param novo_peso
     * @return int
     */
    int operator[](int novo_peso);

private:

    std::shared_ptr<Vertice> destino;
    int peso;
};

} // namespace paa

#endif //PAA_ARESTA_H
