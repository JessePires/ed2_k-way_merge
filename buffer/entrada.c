#include "buffer.h"

Buffer* criarBufferEntrada(char* arquivo, unsigned long int qtdRegistros, FILE *arq_buffer){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = 0;

  if(arq_buffer == NULL) arq_buffer = fopen(arquivo, "rb");
  fread(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, arq_buffer);
  buffer->arq = arq_buffer;
  return buffer;
}

int proximoBuffer(Buffer* buffer){
  if(buffer == NULL) return -1;
  return buffer->proximo+1;
}

ITEM_VENDA* consomeBuffer(Buffer* buffer, int i){
  if(buffer == NULL) return NULL; 
  return &buffer->vet[i];
}

void deletarBuffer(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}
