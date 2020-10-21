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

Buffer* criarBufferEntrada(char* arquivo, unsigned long int qtdRegistros, FILE *arq_buffer);
Buffer* criarBufferSaida(char* arquivo, unsigned long int qtdRegistros);
void deletarBuffer(Buffer *buffer);
void deletarBufferSaida (Buffer *buffer);
void inserirRegistroBufferSaida (Buffer *buffer, char *arquivo, ITEM_VENDA *item);