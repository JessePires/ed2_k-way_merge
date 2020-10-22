#include "buffer.h"

Buffer* criarBufferSaida(char *arquivo, unsigned long int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = 0;

  buffer->arq = fopen(arquivo, "ab");

  return buffer;
}

void inserirRegistroBufferSaida (Buffer *buffer, ITEM_VENDA *item) {
  buffer->vet[buffer->proximo] = *item;

  if (buffer->proximo == buffer->maxsize) {
    despejarBuffer(buffer, buffer->maxsize);
  }

  buffer->proximo++;
}

void despejarBufferSaida (Buffer *buffer) {
  fwrite(buffer->vet, sizeof(ITEM_VENDA), buffer->proximo, buffer->arq);
  buffer->proximo = 0;
}
