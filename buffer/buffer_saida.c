#include "buffer.h"

Buffer* BUFFER_SAIDA_criar(char *arquivo, unsigned long int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));

  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = 0;
  buffer->arq = fopen(arquivo, "wb");

  return buffer;
}

void BUFFER_SAIDA_inserirRegistro (Buffer *buffer, ITEM_VENDA item) {
  if (buffer->proximo == buffer->maxsize) BUFFER_SAIDA_despejar(buffer);

  buffer->vet[buffer->proximo] = item;
  buffer->proximo++;
}

void BUFFER_SAIDA_despejar (Buffer *buffer) {
  fwrite(buffer->vet, sizeof(ITEM_VENDA), buffer->proximo, buffer->arq);
  buffer->proximo = 0;
}
