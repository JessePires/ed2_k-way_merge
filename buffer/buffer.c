#include "buffer.h"

void BUFFER_deletar(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}
