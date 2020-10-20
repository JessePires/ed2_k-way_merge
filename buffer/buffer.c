#include "buffer.h"

Buffer* criarBuffer(char* arquivo, int bytes){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(bytes, sizeof(ITEM_VENDA));
  buffer->maxsize = bytes;
  buffer->qtd = 0;
  buffer->proximo = -1;

  buffer->arq = fopen(arquivo, "rb");
  return buffer;
}

void deletarBugger(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}