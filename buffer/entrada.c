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

static void reencherBuffer(Buffer* buffer){
  if(buffer == NULL) return NULL;
  unsigned long int qtdBytes, posAtual, posFinal, restoRegistros, step;
  fgetpos(buffer->arq, &posAtual);
  fseek(buffer->arq, 0, SEEK_END);
  fgetpos(buffer->arq, &posFinal);
  fsetpos(buffer->arq, &posAtual);

  restoRegistros = (posFinal - posAtual)/sizeof(ITEM_VENDA);
  
  if(restoRegistros > buffer->maxsize) step = buffer->maxsize;
  else  step = restoRegistros;

  buffer->proximo = 0;
  buffer->maxsize = step;
  fread(buffer->arq, sizeof(ITEM_VENDA), step, buffer->arq);

}

int proximoBuffer(Buffer* buffer){
  if(buffer == NULL) return -1;

  if(vazioBuffer(buffer))  reencherBuffer(buffer);

  return buffer->proximo+1;
}

int vazioBuffer(Buffer *buffer){
  if(buffer->proximo == buffer->maxsize) return 1;
  return 0;
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
