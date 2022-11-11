//
// Created by minorro on 6/4/22.
//

#ifndef PAA2_UTIL_H
#define PAA2_UTIL_H

#include <fstream>
#include <vector>
#include <tuple>

namespace paa {

    typedef enum {
        BRANCO,
        CINZA,
        PRETO
    } Cor;

    /**
     * Lê do arquivo se o grafo é orientado
     * @param f arquivo aberto para ler o grafo
     * @return true para orientado, false para não orientado
     */
    bool get_is_orientado(std::ifstream &f);
    /**
     * Lê do arquivo o número de vértices
     * @param f arquivo aberto para ler o grafo
     * @return inteiro com numero de vertices
     */
    int get_n_vertices(std::ifstream &f);
    /**
     * Lê os vertices do arquivo
     * @param f arquivo aberto para ler o grafo
     * @param arestas vetor com as arestas do grafo representadas como tuplas <de, para, peso>
     */
    void get_vertices(std::ifstream &f, std::vector<std::tuple<int, int, int>> &arestas);

}


#endif //PAA2_UTIL_H
