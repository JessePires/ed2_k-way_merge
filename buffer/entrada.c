#include "buffer.h"

int proximoBuffer(Buffer* buffer){
  if(buffer == NULL) return -1;
  return buffer->proximo+1;
}

ITEM_VENDA* consomeBuffer(Buffer* buffer, int i){
  if(buffer == NULL) return NULL; 
  return &buffer->vet[i];
}

<<<<<<< HEAD
void deletarBuffer(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}
=======
int vazioBuffer(Buffer* buffer){
  if(buffer == NULL) return 1;
  
  return (buffer->proximo == buffer->maxsize) ? 0: 1;
}
>>>>>>> c209dcc38a4aa08811dca5255aca99918c46fe21
