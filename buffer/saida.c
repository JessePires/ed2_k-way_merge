#include "buffer.h"

Buffer* criarBufferSaida(char* arquivo,unsigned long int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = -1;

  buffer->arq = fopen(arquivo, "ab");
  fclose(buffer->arq);

  return buffer;
}

void inserirRegistro (Buffer *buffer, char *arquivo, ITEM_VENDA *item) {
  buffer->vet[buffer->proximo] = *item;

  if (buffer->proximo == buffer->maxsize) {
    despejarBuffer(buffer, arquivo, buffer->maxsize);
  }
}

void despejarBuffer (Buffer *buffer, char *nome_arquivo, int qtdRegistros) {
  if (qtdRegistros <= 0) return;

  buffer->arq = fopen(nome_arquivo, "wb");
  fwrite(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, buffer->arq);

  buffer->proximo = 0;
}
