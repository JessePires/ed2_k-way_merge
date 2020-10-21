#pragma once
#include "../big_file.h"
#include <stdio.h>
#include <stdlib.h>

#define STEPOFREAD 10

typedef struct Buffer{
  ITEM_VENDA *vet;
  int maxsize;
  int proximo;
  FILE *arq;
} Buffer;

Buffer* criarBuffer(char* arquivo, int qtdRegistros, FILE *arq_buffer);
void deletarBuffer(Buffer *buffer);
