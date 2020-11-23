#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "big_file/big_file.h"
#include "ordenacao_externa/ordenacao_externa.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main(int argc, char** argv){
  unsigned long int qtdRegistros;
  unsigned long int maximoMemoria;
  unsigned long int tamBufferSaida;
  int div;
  clock_t tempo;

  if(argc != 4){
    qtdRegistros =  256000;
    maximoMemoria = 8388608;
    tamBufferSaida = maximoMemoria/2;
  }else{
    qtdRegistros = atoi(argv[1]);
    maximoMemoria = atoi(argv[2]);
    div = atoi(argv[3]);
    tamBufferSaida = maximoMemoria/div;
  }

  printf("\nGERANDO ARQUIVO ORIGINAL...\n");
  printf("====================================\n");
  gerar_array_iv("teste.dat", qtdRegistros, 42);
  
  tempo = clock();
  ordenacao_externa("teste.dat", maximoMemoria, tamBufferSaida, "saida");
  tempo = clock() - tempo;
  printf("\nOrdenacao finalizada com sucesso!\n");

  int resposta = isSaidaOrdenada("saida");
  if (resposta) printf("A saida esta ordenada\n");
  else printf("A saida não esta ordenada\n");

  printf("Tempo gasto na ordenacao: %f segundos\n", ((float)tempo)/CLOCKS_PER_SEC);
  printf("====================================\n");

  _CrtDumpMemoryLeaks();
  return 0;
}
