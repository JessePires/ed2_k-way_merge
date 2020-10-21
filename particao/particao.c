#include "particao.h"
#include "../big_file.h"
#include "../sorting/quick_sort.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <inttypes.h>


char **criarParticao(char *arquivo, int qtdParticoes){
  char **nomes = calloc(qtdParticoes, sizeof(char*));
  FILE *arq = fopen(arquivo, "rb");

  fseek(arq, 0, SEEK_END);
  int resto = ftell(arq);
  unsigned long int tamanho = ftell(arq)/(1024*qtdParticoes);
  fseek(arq, 0, SEEK_SET);
  
  for(int i = 0; i < qtdParticoes; i++){ 
    char versao[i+1];//tem q mudar isso, por ex se i = 20000 o numero de casas da versão tem q ser 5 
    char extensao[] = ".dat";
    sprintf(versao, "%d", i+1);
    int x = strlen(versao)+strlen(extensao)+1;
    char *nome_arquivo = calloc(x, sizeof(char));

    strcat(nome_arquivo, "p");
    strcat(nome_arquivo, versao);
    strcat(nome_arquivo, extensao);
    nomes[i] = malloc(strlen(nome_arquivo)+1);
    memcpy(nomes[i], nome_arquivo, strlen(nome_arquivo)+1);

    FILE *destino = fopen(nome_arquivo, "wb");
    ITEM_VENDA *aux = calloc(tamanho, sizeof(ITEM_VENDA));

    resto -= tamanho;
    int tam = (resto < 0) ? resto+tamanho : tamanho;
    fread(aux, sizeof(ITEM_VENDA), tam, arq);
    quickSort(aux, 0, tam-1);
    fwrite(aux, sizeof(ITEM_VENDA), tam, destino);
    fclose(destino);
    if(resto < 0) break;
  }

  fclose(arq);
  return nomes;
}

void teste_ordenacao_particao (char *arquivo) {
  unsigned long int i;
  ITEM_VENDA *itens;

  FILE *arq = fopen(arquivo, "rb");

  fseek(arq, 0, SEEK_END);
  unsigned long int tamanho = ftell(arq)/1024;
  fseek(arq, 0, SEEK_SET);

  itens = calloc(tamanho, sizeof(ITEM_VENDA));

  fread(itens, sizeof(ITEM_VENDA), tamanho, arq);

  for (i = 0; i < tamanho; i++) {
    printf("ID: %"PRIu32"\n", itens[i].id);
  }

  fclose(arq);
}
