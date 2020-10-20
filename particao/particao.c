#include "particao.h"
#include "../big_file.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <math.h>

#define PKQTD (1024*100)

void criarParticao(char *arquivo){
    // int aux = limite;
  FILE *arq = fopen(arquivo, "rb");

  fseek(arq, 0, SEEK_END);
  unsigned long int tamanho = ftell(arq)/1024;
  fseek(arq, 0, SEEK_SET);
  int pk = ceil((float)tamanho/PKQTD);
  
  int resto = tamanho;
  for(int i = 0; i < pk; i++){ 
    char numero[1];
    char extensao[] = ".dat";
    char nome1[20] = "p";
    sprintf(numero, "%d", i+1);
    strcat(nome1, numero);
    strcat(nome1, extensao);

    FILE *destino = fopen(nome1, "wb");
    ITEM_VENDA *aux = calloc(PKQTD, sizeof(ITEM_VENDA));

    resto -= PKQTD;
    int tam = (resto < 0) ? resto+PKQTD : PKQTD;
    fread(aux, sizeof(ITEM_VENDA), tam, arq);
    fwrite(aux, sizeof(ITEM_VENDA), tam, destino);
    fclose(destino);
    if(resto < 0) break;
  }

  fclose(arq);
  }
  
