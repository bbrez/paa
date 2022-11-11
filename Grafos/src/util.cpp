//
// Created by minorro on 6/4/22.
//

#include "util.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

namespace paa {

    /**
     * Lê do arquivo se o grafo é orientado
     * @param f arquivo aberto para ler o grafo
     * @return true para orientado, false para não orientado
     */
    bool get_is_orientado(std::ifstream &f){
        std::string orientado;

        f.ignore(std::numeric_limits<std::streamsize>::max(), '='); //ignora caracteres até '='
        f >> orientado;

        std::cout << orientado << '\n';
        if(orientado == "sim") return true;
        if(orientado == "nao") return false;
        return false;
    }

    /**
     * Lê do arquivo o número de vértices
     * @param f arquivo aberto para ler o grafo
     * @return inteiro com numero de vertices
     */
    int get_n_vertices(std::ifstream &f){
        int n_vetices;

        f.ignore(std::numeric_limits<std::streamsize>::max(), '=');
        f >> n_vetices;

        return n_vetices;
    }

    /**
     * Lê os vertices do arquivo
     * @param f arquivo aberto para ler o grafo
     * @param arestas vetor com as arestas do grafo representadas como tuplas <de, para, peso>
     */
    void get_vertices(std::ifstream &f, std::vector<std::tuple<int, int, int>> &arestas){
        while(!f.eof()){
            int de, para, peso;

            f.ignore(std::numeric_limits<std::streamsize>::max(), '(');
            f >> de;

            f.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            f >> para;

            f.ignore(std::numeric_limits<std::streamsize>::max(), ':');
            f >> peso;

            arestas.emplace_back(de, para, peso);
        }

        auto cmp = [](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
            return std::get<1>(a) < std::get<1>(b);
        };

        std::sort(arestas.begin(), arestas.end(), cmp);
    }
}