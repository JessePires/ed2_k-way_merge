#include "buffer.h"
#include <inttypes.h>
void reencherBuffer(Buffer* buffer){
  unsigned long int restoRegistros, step;
  fpos_t posAtual;
  unsigned long int posFinal, qtdBytes;
  
  fgetpos(buffer->arq, &posAtual);
  fseek(buffer->arq, 0, SEEK_END);
  posFinal = ftell(buffer->arq);
  fsetpos(buffer->arq, &posAtual);
  qtdBytes = posFinal - ftell(buffer->arq);

  restoRegistros = qtdBytes/sizeof(ITEM_VENDA);

  if(restoRegistros == 0) return;
  
  if(restoRegistros > buffer->maxsize) step = buffer->maxsize;
  else  step = restoRegistros;

  buffer->proximo = 0;
  buffer->maxsize = step;
  fread(buffer->vet, sizeof(ITEM_VENDA), step, buffer->arq);

}

Buffer* criarBufferEntrada(char* arquivo, unsigned long int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = 0;

  buffer->arq = fopen(arquivo, "rb");
  fread(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, buffer->arq);
  return buffer;
}

int proximoBuffer(Buffer* buffer){
  if(buffer == NULL) return -1;

  if(buffer->proximo == buffer->maxsize)  reencherBuffer(buffer);
  if(buffer->proximo < buffer->maxsize) return buffer->proximo++;
}

ITEM_VENDA* consomeBuffer(Buffer* buffer, int i){
  if(buffer == NULL) return NULL; 
  return &buffer->vet[i];
}

int vazio(Buffer *buffer){
  if(buffer == NULL) return 1;

  fpos_t posAtual;
  unsigned long int  restoRegistros, posFinal, qtdBytes;
  fgetpos(buffer->arq, &posAtual);
  fseek(buffer->arq, 0, SEEK_END);
  posFinal = ftell(buffer->arq);
  fsetpos(buffer->arq, &posAtual);
  qtdBytes = posFinal - ftell(buffer->arq);

  restoRegistros = qtdBytes/sizeof(ITEM_VENDA);

  return (restoRegistros == 0) ? 1 : 0;
}

int bufferVazio(Buffer *buffer){
  return (buffer->proximo == buffer->maxsize) ? 1 : 0;
}

void deletarBuffer(Buffer *buffer){
  fclose(buffer->arq);
  free(buffer->vet);
  free(buffer);
}
