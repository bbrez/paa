#include <stdio.h>
#include <chrono> //para medir tempo de execução

#include <cuda_runtime.h>

/**
 * @brief Kernel para soma de dois vetores na gpu (C[i] = A[i] + B[i])
 * @param A ponteiro para vetor A na gpu
 * @param B ponteiro para vetor B na gpu
 * @param C ponteiro para vetor de resultado na gpu
 * @param numElements número de elementos dos vetores, deve ser igual para todos
 */
__global__ void vectorAdd(const float *A, const float *B, float *C, int numElements) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;

    //Verifica se a thread está dentro do vetor ainda
    if(i < numElements){
        C[i] = A[i] + B[i]; 
    }
}


int main () {
    auto numElementos = 1000000; //quantidade de elementos
    size_t size = numElementos * sizeof(float); //quantidade de bytes de cada vetor

    float *mem_A = (float *) malloc(size); //Vetor A na memória principal
    float *mem_B = (float *) malloc(size); //Vetor B na memória principal
    float *mem_C = (float *) malloc(size); //Vetor C na memória principal

    //Inicializar vetores com números aleatórios
    printf("Inicializando Vetores...\n");
    for(int i = 0 ; i < numElementos ; ++i){
        mem_A[i] = rand() / (float)RAND_MAX;
        mem_B[i] = rand() / (float)RAND_MAX;
    }

    cudaFree(0); //"Acorda" a GPU

    auto overhead_comeco = std::chrono::high_resolution_clock::now();
    float *gpu_A = nullptr; //Vetor A na memória da GPU
    cudaMalloc((void **) &gpu_A, size);
    cudaMemcpy(gpu_A, mem_A, size, cudaMemcpyHostToDevice); //Copia dados do vetor A na memoria principal para GPU

    float *gpu_B = nullptr; //Vetor B na memória da GPU
    cudaMalloc((void **) &gpu_B, size);
    cudaMemcpy(gpu_B, mem_B, size, cudaMemcpyHostToDevice); //Copia dados do vetor B na memoria principal para GPU

    float *gpu_C = nullptr; //Vetor C na memória da GPU
    cudaMalloc((void **) &gpu_C, size);
    auto overhead_fim = std::chrono::high_resolution_clock::now();
    printf("Tempo para copiar dados para GPU: %lluus\n",
        std::chrono::duration_cast<std::chrono::microseconds>(overhead_fim - overhead_comeco).count());

    cudaDeviceProp props_gpu;
    cudaGetDeviceProperties(&props_gpu, 0); //Lê as propriedades da GPU

    int threadsPerBlock = props_gpu.maxThreadsPerBlock; //Quantidade de threads paralelas por bloco de execução
    int blocksPerGrid = (numElementos + threadsPerBlock - 1) / threadsPerBlock; //quantidade de blocos por lote
    printf("Executando kernel CUDA com %d blocos de %d threads para %ld elementos\n", blocksPerGrid, threadsPerBlock, numElementos);

    auto comeco = std::chrono::high_resolution_clock::now(); //Timestamp de inicio da execução

    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(gpu_A, gpu_B, gpu_C, numElementos); //Executa o kernel

    auto fim = std::chrono::high_resolution_clock::now(); //Timestamp de fim da execução
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim-comeco); //Diferença entre os timestamps
    printf("Tempo de execução: %lluus\n", duracao.count());

    printf("Copiando resultados...\n");
    cudaMemcpy(mem_C, gpu_C, size, cudaMemcpyDeviceToHost); //Copia resultados da gpu para memoria principal

    //Verifica se os resultados estão corretos
    printf("Verificando Resultados...\n");
    comeco = std::chrono::high_resolution_clock::now();

    for(int i  = 0 ; i < numElementos ; ++i){
        if(mem_A[i] + mem_B[i] != mem_C[i]){
            printf("Erro verificando resultado no elemento %d\n", i);
        }
    }

    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim-comeco);
    printf("Tempo de verificação: %lluus\n", duracao.count());

    //Desaloca memória
    cudaFree(gpu_A);
    cudaFree(gpu_B);
    cudaFree(gpu_C);

    free(mem_A);
    free(mem_B);
    free(mem_C);
}