#include <inttypes.h>
#include "buffer.h"

Buffer* BUFFER_ENTRADA_criar(char* arquivo, unsigned long int qtdRegistros){
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->vet = calloc(qtdRegistros, sizeof(ITEM_VENDA));
  buffer->maxsize = qtdRegistros;
  buffer->proximo = 0;

  buffer->arq = fopen(arquivo, "rb");
  fread(buffer->vet, sizeof(ITEM_VENDA), qtdRegistros, buffer->arq);
  return buffer;
}

int BUFFER_ENTRADA_proximo(Buffer* buffer){
  if(buffer == NULL) return -1;

  return buffer->proximo++;
}

ITEM_VENDA* BUFFER_ENTRADA_consumir(Buffer* buffer, int i){
  if(buffer == NULL) return NULL;
  ITEM_VENDA *retorno = calloc(1, sizeof(ITEM_VENDA));
  *retorno = buffer->vet[i];
  if(buffer->proximo == buffer->maxsize)  BUFFER_ENTRADA_reencher(buffer);
  return retorno;
}

int BUFFER_ENTRADA_vazio(Buffer *buffer){
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

int BUFFER_ENTRADA_bufferVazio(Buffer *buffer){
  return (buffer->proximo == buffer->maxsize) ? 1 : 0;
}

void BUFFER_ENTRADA_reencher(Buffer* buffer){
  fpos_t posAtual;
  unsigned long int posFinal, qtdBytes, restoRegistros, step;
  
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