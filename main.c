#include <stdio.h>
#include <stdlib.h>
#include "big_file.h"
#include "ordenacao_externa/ordenacao_externa.h"

#define MB100 104857600
#define MB10 10485760

int main(int argc, char** argv){
  printf("\nGERANDO ARQUIVO ORIGINAL...\n");
  printf("====================================\n");
  gerar_array_iv("teste.dat", (1572864/5), 42);
  ordenacao_externa("teste.dat", MB100, MB10, "saida.dat");

  int resposta = isSaidaOrdenada("saida.dat");
  if (resposta) printf("A saída está ordenada\n");
  else printf("A saída não está ordenada\n");  
  printf("====================================\n");

  return 0;
}
