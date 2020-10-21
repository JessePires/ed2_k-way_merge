#pragma once
#include "../big_file.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Buffer{
  ITEM_VENDA *vet;
  int maxsize;
  int proximo;
  FILE *arq;
} Buffer;

Buffer* criarBuffer(char* arquivo, int qtdRegistros);
void deletarBugger(Buffer *buffer);

int proximoBuffer(Buffer* buffer);
ITEM_VENDA* consomeBuffer(Buffer* buffer, int i);
int vazioBuffer(Buffer* buffer); 