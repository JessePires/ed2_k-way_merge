#include "buffer.h"


Buffer* criarBuffer(char* arquivo){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(STEPOFREAD, sizeof(ITEM_VENDA));
  buffer->maxsize = STEPOFREAD;
  buffer->qtd = 0;

  buffer->arq = fopen(arquivo, "rb");
  return buffer;
}

void deletarBugger(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}