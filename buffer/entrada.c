#include "buffer.h"

int proximoBuffer(Buffer* buffer){
  if(buffer == NULL) return -1;
  return buffer->proximo+1;
}

ITEM_VENDA* consomeBuffer(Buffer* buffer, int i){
  if(buffer == NULL) return NULL; 
  return &buffer->vet[i];
}

int vazioBuffer(Buffer* buffer){
  if(buffer == NULL) return 1;
  
  return (buffer->proximo == buffer->maxsize) ? 0: 1;
}
