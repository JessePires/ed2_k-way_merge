#include "buffer.h"

Buffer* criarBuffer(char* arquivo, int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->qtdRegistros = 0;
  buffer->proximo = -1;

  buffer->arq = fopen(arquivo, "rb");
  fread(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, buffer->arq);
  return buffer;
}

void deletarBugger(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}