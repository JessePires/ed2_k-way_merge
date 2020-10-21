#include "buffer.h"

void inserirRegistro (Buffer *buffer, ITEM_VENDA *item) {
  buffer->vet[proximo++] = item;

  if (buffer->proximo == buffer->maxsize) {
    despejarBuffer(buffer, buffer->maxsize);
  }
}

void despejarBuffer (Buffer *buffer, char *nome_arquivo, int qtdRegistros) {
  if (qtdRegistros <= 0) return;

  buffer->arq = fopen(nome_arquivo, "wb");
  frwrite(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, buffer->arq);

  buffer->proximo = 0;
}
