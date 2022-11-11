//
// Created by minorro on 5/16/22.
//

#include "GrafoOrientado.h"

#include <memory>
#include <limits>
#include <iostream>

namespace paa {
    /**
     * Construtor para um grafo Orientado
     * @param nVert número de vertices do grafo
     */
    GrafoOrientado::GrafoOrientado(int nVert) : Grafo(nVert) {}
    /**
     * Construtor para um Grafo Orientado com arestas inseridas
     * @param nVert número de vértices do grafo
     * @param arestas vetor de tuplas representando arestas <de, para, peso>
     */
    GrafoOrientado::GrafoOrientado(int nVert, const std::vector<std::tuple<int, int, int>>& arestas) : Grafo(nVert) {
        for(const auto &a: arestas){
            auto [de, para, peso] = a;
            this->addAresta(de, para, peso);
        }
    }

    /**
     * Adiciona uma aresta no Grafo
     * @param de origem da aresta
     * @param para destino da aresta
     * @param peso peso da aresta
     */
    void GrafoOrientado::addAresta(int de, int para, int peso) {
        this->getVertice(de)->addAresta(std::make_shared<Aresta>(this->getVertice(para), peso));
    }

    /**
     * Faz a relaxação de uma aresta para o algoritmo de Bellman-Ford
     * @param v1 vertice origem
     * @param v2 vertice destino
     * @param peso peso da aresta
     * @param distancias vetor de distancias
     * @param pi vetor de predecessores
     */
    void GrafoOrientado::relax(int v1, int v2, int peso, std::vector<int> &distancias, std::vector<int> &pi) const {
        if(distancias[v2] > distancias[v1] + peso){
            distancias[v2] = distancias[v1] + peso;
            pi[v2] = v1;
        }
    }

    /**
     * Inicializa a origem para o agloritmo de Bellman-Ford
     * @param v vertice origem
     * @param distancias vetor de distancias
     * @param pi vetor de predecessores
     */
    void GrafoOrientado::inicializa_origem(int v, std::vector<int> &distancias, std::vector<int> &pi) const {
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            distancias.emplace_back(100000);
            pi.emplace_back(100000);
        }
        distancias[v] = 0; // NIL
        pi[v] = -1;
    }

    /**
     * Função auxiliar para fazer a resposta do algoritmo de bellman-ford
     * @param origem
     * @param dest
     * @param pi
     * @return
     */
    std::string constroi_caminho(int origem, int dest, std::vector<int> &pi) {
        std::string caminho = std::to_string(dest);
        if(pi[dest] == -1 || pi[dest] == std::numeric_limits<int>::max()){
            return caminho;
        } else {
            return constroi_caminho(origem, pi[dest], pi) + " - " + caminho;
        }
    }

    /**
     * Executa algoritmo de Bellman-Ford no Grafo
     * @param origem posição do vértice inicial no grafo
     */
    void GrafoOrientado::bellman_ford(int origem) const {
        std::vector<int> distancias, pi;

        inicializa_origem(origem, distancias, pi);

        //aplica relaxação
        for(unsigned int k = 0 ; k < this->vertices.size() -1 ; ++k){
        for(unsigned int i = 0 ; i < this->vertices.size(); ++i){
            for(unsigned int j = 0 ; j < this->vertices[i]->numArestas() ; ++j){
                auto aresta = this->vertices[i]->getAresta(j);
                this->relax(i, this->posVertice(aresta->getDestino()), aresta->getPeso(), distancias, pi);
            }
        }}

        //verifica se há ciclo de peso negativo
        for(const auto &vertice : this->vertices){
            for(unsigned int j = 0; j < vertice->numArestas(); ++j){
                if(distancias[this->posVertice(vertice->getAresta(j)->getDestino())] > distancias[this->posVertice(vertice)] + vertice->getAresta(j)->getPeso()){
                    std::cout << "O grafo possui ciclos negativos";
                    return;
                }
            }
        }

        //mostra resultado
        std::cout << "origem: " << origem << '\n';
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            std::cout << "destino: " << i << " dist.: " << distancias[i] << " caminho: " << constroi_caminho(origem, i, pi) << '\n';
        }
    }
} // paa