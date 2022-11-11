#include <vector>
#include <tuple>
#include <iostream>

#include "GrafoOrientado.h"
#include "GrafoNaoOrientado.h"
#include "util.h"

int main() {

    std::ifstream entrada("grafo7.txt");
    bool is_orientado = paa::get_is_orientado(entrada);
    int n_vertices = paa::get_n_vertices(entrada);
    std::vector<std::tuple<int, int, int>> vertices;
    paa::get_vertices(entrada, vertices);

    std::shared_ptr<paa::Grafo> g;
    if(is_orientado){
        auto go = std::make_shared<paa::GrafoOrientado>(n_vertices, vertices);
        go->bellman_ford(3);
        g = go;
    } else {
        g = std::make_shared<paa::GrafoNaoOrientado>(n_vertices, vertices);
    }

    //g->printGrafo();
    std::cout << '\n';
    g->busca_profundidade(3);
    std::cout << '\n';
    g->busca_largura(3);
    std::cout << '\n';
    return 0;
}
