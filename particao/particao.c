#include "particao.h"
#include "../big_file.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <math.h>

void criarParticao(char *arquivo, int qtdParticoes){
  FILE *arq = fopen(arquivo, "rb");

  fseek(arq, 0, SEEK_END);
  int resto = ftell(arq);
  unsigned long int tamanho = ftell(arq)/(1024*qtdParticoes);
  fseek(arq, 0, SEEK_SET);
  
  for(int i = 0; i < qtdParticoes; i++){ 
    char numero[1];
    char extensao[] = ".dat";
    char nome1[20] = "p";
    sprintf(numero, "%d", i+1);
    strcat(nome1, numero);
    strcat(nome1, extensao);

    FILE *destino = fopen(nome1, "wb");
    ITEM_VENDA *aux = calloc(tamanho, sizeof(ITEM_VENDA));

    resto -= tamanho;
    int tam = (resto < 0) ? resto+tamanho : tamanho;
    fread(aux, sizeof(ITEM_VENDA), tam, arq);
    fwrite(aux, sizeof(ITEM_VENDA), tam, destino);
    fclose(destino);
    if(resto < 0) break;
  }

  fclose(arq);
  }
  
