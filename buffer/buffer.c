#include "buffer.h"

Buffer* criarBuffer(char* arquivo, int qtdRegistros, FILE *arq_buffer){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = -1;

  if(arq_buffer == NULL) arq_buffer = fopen(arquivo, "rb");
  fread(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, arq_buffer);
  buffer->arq = arq_buffer;
  return buffer;
}

void deletarBugger(Buffer *buffer){

  free(buffer->vet);
  free(buffer);
}