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

Buffer* criarBufferEntrada(char* arquivo, unsigned long int qtdRegistros);
Buffer* criarBufferSaida(char* arquivo, unsigned long int qtdRegistros);
void deletarBuffer(Buffer *buffer);
ITEM_VENDA* consomeBuffer(Buffer* buffer, int i);
void inserirRegistroBufferSaida (Buffer *buffer, ITEM_VENDA *item);

void despejarBufferSaida (Buffer *buffer);
int proximoBuffer(Buffer* buffer);
int vazio(Buffer *buffer);
void reencherBuffer(Buffer* buffer);
int bufferVazio(Buffer *buffer);