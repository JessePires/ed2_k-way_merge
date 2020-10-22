#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "big_file.h"
#include "buffer/buffer.h"
#include "particao/particao.h"
#include <math.h>
#include <inttypes.h>

#define MB100 104857600
#define MB10 10485760

void intercalacao_k_vias(Buffer **entrada, Buffer *saida, unsigned long int qtd_buffer_entrada){
  int qtd_buffers_vazios = 0;

  while (qtd_buffers_vazios < qtd_buffer_entrada) {
    Buffer *menor;
    uint32_t auxmenor = INT32_MAX;

    qtd_buffers_vazios = 0;
    for(int i = 0; i < qtd_buffer_entrada; i++){
      Buffer *teste = entrada[i];
      if (entrada[i]->proximo != entrada[i]->maxsize){
        if(auxmenor > entrada[i]->vet[entrada[i]->proximo].id){
          auxmenor = entrada[i]->vet[entrada[i]->proximo].id;
          menor = entrada[i];
        }
      }else if(!vazio(entrada[i])){
        reencherBuffer(entrada[i]);
      }else qtd_buffers_vazios++;
    }

    if(auxmenor != INT32_MAX){
      ITEM_VENDA *menor_item = consomeBuffer(menor, proximoBuffer(menor));
      printf("ID_MENOR: %"PRIu32"\n", menor_item->id);
      inserirRegistroBufferSaida(saida, menor_item);
    }
  }
  despejarBufferSaida(saida);
}

void ordenacao_externa(char *entrada, unsigned long int bytes_registros, unsigned long int bytes_buffer_saida, char *nome_saida){
  FILE *arq = fopen(entrada, "rb");
  fseek(arq, 0, SEEK_END);
  int e = ftell(arq);
  fclose(arq);
  
  int k = ceil((float)e/bytes_registros);
  unsigned long int qtd_registro_entrada = floor(((float)(bytes_registros-bytes_buffer_saida)/k)/sizeof(ITEM_VENDA));
  char **pk = criarParticao(entrada, k);

  //CRIANDO BUFFER
  Buffer **buffer_entrada = calloc(k, sizeof(Buffer*));
  for(int i = 0; i < k; i++) {
    buffer_entrada[i] = criarBufferEntrada(pk[i], qtd_registro_entrada);
  }

  Buffer *buffer_saida = criarBufferSaida(nome_saida, bytes_buffer_saida/sizeof(ITEM_VENDA));

  intercalacao_k_vias(buffer_entrada, buffer_saida, k);

  deletarBuffer(buffer_saida);
  printf("FINALIZADO\n");
}

int isSaidaOrdenada (char *nome_arquivo) {
  ITEM_VENDA *item_anterior;
  ITEM_VENDA *item_atual;

  FILE *arq = fopen(nome_arquivo, "rb");
  
  if(arq == NULL) {
    printf("Impossível abrir o arquivo!\n");
    return -1;
  }

  fread(item_anterior, sizeof(ITEM_VENDA), 1, arq);
  
  while(fread(item_atual, sizeof(ITEM_VENDA), 1, arq) != EOF) {
    if (item_atual < item_anterior) return 0;

    item_anterior = item_atual;
  }

  return 1;
}

int main(int argc, char** argv){
  gerar_array_iv("teste.dat", (1572864/5), 42);
  ordenacao_externa("teste.dat", MB100, MB10, "saida.dat");
  int resposta = isSaidaOrdenada("saida");
  if (resposta == 1) {
    printf("A saída está ordenada\n");
  }else if (resposta == 0) {
    printf("A saída não está ordenada\n");
  }

  return 0;
}
 