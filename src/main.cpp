#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "Compressor.h"
#include "Decompressor.h"

int main() {

	//Código para arrumar acentuação de palavras
#if defined(__unix__)
    std::setlocale(LC_ALL, "pt_BR.UTF-8");
#elif defined(_WIN32) || defined(_WIN64)
	std::system("chcp 65001 > nul");
#endif

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

			auto start = std::chrono::high_resolution_clock::now();
            if(selecionado == 1 || selecionado == 2){ //compressão
                paa::FileReader::MODE m = selecionado==1 ? paa::FileReader::MODE::word : paa::FileReader::MODE::character;
                entrada.open(ifn);
                paa::FrequencyMap fm(entrada, m);
                entrada.close();
                //fm.print();

                paa::HuffmanCode hc(fm);
                paa::Compressor c(hc);
                entrada.open(ifn);
                saida.open(ofn, std::ios::binary);
                c.compress(entrada, m, saida);
            } else if(selecionado == 3){ //descompressão
                entrada.open(ifn, std::ios::binary);
                saida.open(ofn);
                paa::Decompressor d;
                d.decompress(entrada, saida);
            } else std::cout << "Opção Inválida\n";

			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
			std::cout << "Tempo de execução: " << duration.count() << " milisegundos\n";
        }
    }
}
