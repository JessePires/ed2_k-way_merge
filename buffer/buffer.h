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

Buffer* BUFFER_ENTRADA_criar(char* arquivo, unsigned long int qtdRegistros);
int BUFFER_ENTRADA_proximo(Buffer* buffer);
ITEM_VENDA* BUFFER_ENTRADA_consumir(Buffer* buffer, int i);
int BUFFER_ENTRADA_vazio(Buffer *buffer);
int BUFFER_ENTRADA_bufferVazio(Buffer *buffer);
void BUFFER_ENTRADA_reencher(Buffer* buffer);

Buffer* BUFFER_SAIDA_criar(char* arquivo, unsigned long int qtdRegistros);
void BUFFER_SAIDA_inserirRegistro (Buffer *buffer, ITEM_VENDA *item);
void BUFFER_SAIDA_despejar (Buffer *buffer);

void BUFFER_deletar(Buffer *buffer);
