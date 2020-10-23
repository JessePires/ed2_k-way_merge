#include <stdio.h>
#include <stdlib.h>
#include "big_file/big_file.h"
#include "ordenacao_externa/ordenacao_externa.h"

int main(int argc, char** argv){
  unsigned long int qtdRegistros;
  unsigned long int maximoMemoria;
  unsigned long int tamBufferSaida;
  int div;
  if(argc != 4){
    qtdRegistros =  256000;
    maximoMemoria = 8388608;
    tamBufferSaida = maximoMemoria/8;
  }else{
    qtdRegistros = atoi(argv[1]);
    maximoMemoria = atoi(argv[2]);
    div = atoi(argv[3]);
    tamBufferSaida = maximoMemoria/div;
  }



  printf("\nGERANDO ARQUIVO ORIGINAL...\n");
  printf("====================================\n");
  gerar_array_iv("teste.dat", qtdRegistros, 42);
  ordenacao_externa("teste.dat", maximoMemoria, tamBufferSaida, "saida");

  int resposta = isSaidaOrdenada("saida");
  if (resposta) printf("A saída está ordenada\n");
  else printf("A saída não está ordenada\n");  
  printf("====================================\n");

  return 0;
}
