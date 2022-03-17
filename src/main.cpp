#include <iostream>
#include <vector>
#include <string>

#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "Compressor.h"
#include "Decompressor.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    bool running = true;
    while(running){
        std::vector<std::string> opcoes {"Comprimir por palavra",
                                         "Comprimir por letra",
                                         "Descomprimir",
                                         "Sair"};

        for(unsigned long i = 0 ; i < opcoes.size(); ++i){
            std::cout << i+1 << " - " << opcoes[i] << '\n';
        }

        int selecionado = 0;
        std::cout << "Seleção: ";
        std::cin >> selecionado;

        std::ifstream entrada;
        std::ofstream saida;
        if(selecionado == 4) running = false;
        else {
            std::string ifn, ofn;
            std::cout << "Caminho do arquivo de entrada: ";
            std::cin >> ifn;

            std::cout << "Caminho do arquivo de saida: ";
            std::cin >> ofn;

            if(selecionado == 1 || selecionado == 2){
                FileReader::MODE m = selecionado==1 ? FileReader::MODE::word : FileReader::MODE::character;
                entrada.open(ifn);
                FrequencyMap fm(entrada, m);
                entrada.close();
                //fm.print();

                HuffmanCode hc(fm);
                hc.build_tree();

                Compressor c(hc);
                entrada.open(ifn);
                saida.open(ofn, std::ios::binary);
                c.compress(entrada, m, saida);
            } else if(selecionado == 3){
                entrada.open(ifn, std::ios::binary);
                saida.open(ofn);
                Decompressor d;
                d.decompress(entrada, saida);
            } else std::cout << "Opção Inválida\n";
        }
    }
}
