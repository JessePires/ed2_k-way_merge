#pragma once
#include "./big_file.h"
#define STEPOFREAD 10

typedef struct Buffer{
  ITEM_VENDA *vet;
  int maxsize;
  int qtd;
  FILE *arq;
} Buffer;

Buffer* criarBuffer(char* arquivo);
void deletarBugger(Buffer *buffer);