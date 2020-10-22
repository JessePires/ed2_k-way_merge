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
  if(BUFFER_ENTRADA_bufferVazio(buffer))  BUFFER_ENTRADA_reencher(buffer);
  return retorno;
}

int BUFFER_ENTRADA_vazio(Buffer *buffer){
  if(buffer == NULL) return 1;

  fpos_t posAtual;
  unsigned long int posFinal, qtdBytes, restoRegistros;
  
  fgetpos(buffer->arq, &posAtual);
  fseek(buffer->arq, 0, SEEK_END);
  posFinal = ftell(buffer->arq);
  fsetpos(buffer->arq, &posAtual);
  qtdBytes = posFinal - ftell(buffer->arq);

  restoRegistros = qtdBytes/sizeof(ITEM_VENDA);

  if(restoRegistros == 0) return 1;

  if(restoRegistros < buffer->maxsize) buffer->maxsize = restoRegistros;
  return 0;
}

int BUFFER_ENTRADA_bufferVazio(Buffer *buffer){
  return (buffer->proximo == buffer->maxsize) ? 1 : 0;
}

void BUFFER_ENTRADA_reencher(Buffer* buffer){
  if(BUFFER_ENTRADA_vazio(buffer)) return;

  buffer->proximo = 0;
  fread(buffer->vet, sizeof(ITEM_VENDA), buffer->maxsize, buffer->arq);
}
