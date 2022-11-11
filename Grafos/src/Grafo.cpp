//
// Created by minorro on 5/16/22.
//

#include "Grafo.h"
#include "util.h"

#include <iostream>
#include <deque>

namespace paa {

    /**
     * Construtor Grafo
     * @param nVert numero de vertices no grafo
     */
    Grafo::Grafo(int nVert) {
        for(int i = 0 ; i < nVert ; ++i){
            std::shared_ptr<Vertice> vp(new Vertice());
            this->addVertice(vp);
        }
    }

    /**
     * Adiciona um vertice no grafo
     * @param v ponteiro do vertice a ser adicionado
     */
    void Grafo::addVertice(const std::shared_ptr<Vertice>& v) {
        this->vertices.push_back(v);
    }

    /**
     * Adiciona multiplos vertices no grafo
     * @param vv vetor de vertices a serem adicionados.
     */
    void Grafo::addVertices(const std::vector<std::shared_ptr<Vertice>> &vv) {
        this->vertices.insert(this->vertices.begin(), vv.begin(), vv.end());
    }

    /**
     * Pega um vertice na posição pos
     * @param pos posição do vertice
     * @return vertice escolhido
     */
    std::shared_ptr<Vertice> Grafo::getVertice(int pos) const {
        return this->vertices.at(pos);
    }

    /**
     * Encontra a posição de um vertice no vetor de vertices
     * @param v vertice a ser encontrado
     * @return posição
     */
    unsigned int Grafo::posVertice(const std::shared_ptr<Vertice>& v) const {
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            if(this->vertices[i] == v) return i;
        }

        return -1;
    }

    /**
     * Printa o grafo no terminal
     */
    void Grafo::printGrafo() const {

        std::cout << "{ ";
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            for(unsigned int j = 0 ; j < this->vertices[i]->numArestas() ; ++j){
                std::cout << "(" << i << "," << this->posVertice(this->vertices[i]->getAresta(j)->getDestino())
                << "):" << this->vertices[i]->getAresta(j)->getPeso();
                if(j < this->vertices[i]->numArestas() - 1) std::cout << ", ";
            }
            if(i < this->vertices.size() - 1) std::cout << ", ";
        }
        std::cout << " }";
    }

    /**
     * Visita um vertice na busca em profundidade
     * @param v_atual posição do vertice atual
     * @param estado estado de visita de cada vertice
     */
    void Grafo::visita_busca_profundidade(unsigned int v_atual, std::vector<Cor> &estado) const {
        estado[v_atual] = CINZA;

        std::cout << v_atual;
        for(unsigned int i  = 0 ; i < this->vertices[v_atual]->numArestas() ; ++i){
            auto dest_aresta = this->vertices[v_atual]->getAresta(i)->getDestino();
            if(estado[this->posVertice(dest_aresta)] == BRANCO){
                std::cout << " - ";
                visita_busca_profundidade(this->posVertice(dest_aresta), estado);
            }
        }

        estado[v_atual] = PRETO;
    }

    /**
     * algoritmo de busca em profundidade
     * @param inicial vertice para iniciar a busca
     */
    void Grafo::busca_profundidade(int inicial) const {
        std::vector<Cor> estado;
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            estado.emplace_back(BRANCO);
        }

        this->visita_busca_profundidade(inicial, estado);
    }

    /**
     * Visita os vertices na busca em largura
     * @param v_atual vertice inicial
     * @param estado estado de visita de cada vertice
     */
    void Grafo::visita_busca_largura(unsigned int v_atual, std::vector<Cor> &estado) const {
        std::deque<std::shared_ptr<Vertice>> fila;

        estado[v_atual] = CINZA;
        fila.emplace_back(this->getVertice(v_atual));

        std::cout << this->posVertice(fila[0]);

        while(!fila.empty()){
            auto v = fila.at(0);

            for(unsigned int i = 0 ; i < v->numArestas() ; ++i){
                auto destino = v->getAresta(i)->getDestino();
                if(estado[this->posVertice(destino)] == BRANCO){
                    estado[this->posVertice(destino)] = CINZA;
                    fila.emplace_back(destino);
                }
            }

            fila.pop_front();

            if(!fila.empty()){
                std::cout << " - " << this->posVertice(fila.at(0));
            }
        }
    }

    /**
     * Algoritmo de busca em largura no grafo
     * @param inicial posição do vertice para iniciar a busca
     */
    void Grafo::busca_largura(int inicial) const {
        std::vector<Cor> estado;
        for(unsigned int i = 0 ; i < this->vertices.size() ; ++i){
            estado.emplace_back(BRANCO);
        }

        this->visita_busca_largura(inicial, estado);
    }

    void Grafo::kruskal() const {

    }

    void Grafo::prim(int inicial) const {
    }
}