#include "buffer.h"

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
