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
      // printf("ID_MENOR: %"PRIu32"\n", menor_item->id);
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
  
  printf("Tamanho do arquivo: %d MB's\n", (e/1024)/1024);
  printf("Particionaremos em %d vezes, cada um com %.2f MB's\n", k, (float)((e/1024)/1024)/k);
  printf("Teremos %d buffers de entrada, cada um com %.2f MB's\n", k, (float)(qtd_registro_entrada)/sizeof(ITEM_VENDA));
  printf("Teremos 1 buffer de saida, com %.2f MB's\n", (float)bytes_buffer_saida/(sizeof(ITEM_VENDA)*sizeof(ITEM_VENDA)));
  printf("====================================\n");

  printf("\n1 - Criando particoes, por favor aguarde...");
  char **pk = criarParticao(entrada, k);
  
  //CRIANDO BUFFER
  printf("\n2 - Preenchendo buffers, por favor aguarde...");
  Buffer **buffer_entrada = calloc(k, sizeof(Buffer*));
  for(int i = 0; i < k; i++) buffer_entrada[i] = criarBufferEntrada(pk[i], qtd_registro_entrada);
  Buffer *buffer_saida = criarBufferSaida(nome_saida, bytes_buffer_saida/sizeof(ITEM_VENDA));

  printf("\n3 - Ordenando arquivos, por favor aguarde...");
  intercalacao_k_vias(buffer_entrada, buffer_saida, k);

  printf("\n====================================\n");
  printf("Ordenacao finalizada com sucesso!");
}

int main(int argc, char** argv){

  printf("\nGERANDO ARQUIVO ORIGINAL...\n");
  printf("====================================\n");
  // gerar_array_iv("teste.dat", (1572864/5), 42);
  ordenacao_externa("teste.dat", MB100, MB10, "saida.dat");
  printf("\n====================================\n");



  return 0;
}
 