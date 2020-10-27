#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>
#include "../buffer/buffer.h"
#include "../big_file/big_file.h"
#include "../particao/particao.h"

void intercalacao_k_vias(Buffer **entrada, Buffer *saida, unsigned long int qtd_buffer_entrada){
  int qtd_buffers_vazios = 0;

  //ENQUANTO TODOS OS BUFFER NÃO ESTIVEREM VAZIOS REALIZO LAÇO ABAIXO
  while (qtd_buffers_vazios < qtd_buffer_entrada) {
    Buffer *menor;
    uint32_t auxmenor = INT32_MAX;

    qtd_buffers_vazios = 0;
    for(int i = 0; i < qtd_buffer_entrada; i++){
        if (!BUFFER_ENTRADA_bufferVazio(entrada[i])){
          if(auxmenor > entrada[i]->vet[entrada[i]->proximo].id){
            auxmenor = entrada[i]->vet[entrada[i]->proximo].id;
            menor = entrada[i];
          }
        }else qtd_buffers_vazios++;
    }

    //CASO AUXMENOR CONTINUE SENDO INT32_MAX ENTÃO TODOS OS BUFFERS FORAM CONSUMIDOS
    //CASO CONTRARIO BUSCAMOS O ITEM REFERENTE AO ID, BUFFER É REECHIDO "AUTOMATICAMENTE"
    if(auxmenor != INT32_MAX){
      ITEM_VENDA menor_item = BUFFER_ENTRADA_consumir(menor, BUFFER_ENTRADA_proximo(menor));
      BUFFER_SAIDA_inserirRegistro(saida, menor_item);
    }
  }
  BUFFER_SAIDA_despejar(saida);
  
}

void ordenacao_externa(char *entrada, unsigned long int bytes_registros, unsigned long int bytes_buffer_saida, char *nome_saida){
  //ABRO ARQUIVO DE ENTRADA PARA SABER SEU TAMANHO
  FILE *arq = fopen(entrada, "rb");
  fseek(arq, 0, SEEK_END);
  int e = ftell(arq);
  fclose(arq);

  //CALCULO QUANTAS PARTIÇÕES E REGISTRO NO BUFFER DE ENTRADA DEVO TER
  int k = ceil((float)e/bytes_registros);
  unsigned long int qtd_registro_entrada = floor(((float)(bytes_registros-bytes_buffer_saida)/k)/sizeof(ITEM_VENDA));
  
  printf("Tamanho do arquivo: %ld MB's\n", (e/sizeof(ITEM_VENDA))/sizeof(ITEM_VENDA));
  printf("Particionaremos em %d vezes, cada um com %.3f MB's\n", k, (float)((e/sizeof(ITEM_VENDA))/sizeof(ITEM_VENDA))/k);
  printf("Teremos %d buffers de entrada, cada um com %.3f MB's\n", k, (float)(qtd_registro_entrada)/sizeof(ITEM_VENDA));
  printf("Teremos 1 buffer de saida, com %.3f MB's\n", (float)bytes_buffer_saida/(sizeof(ITEM_VENDA)*sizeof(ITEM_VENDA)));
  printf("====================================\n");

  printf("1 - Criando particoes, por favor aguarde...");
  //CRIO AS K-PARTIÇÕES
  char **nome_particoes = criarParticao(entrada, k);
  
  printf("\n2 - Preenchendo buffers, por favor aguarde...");
  //INICIALIZO OS BUFFERS
  Buffer **buffer_entrada = calloc(k, sizeof(Buffer*));
  for(int i = 0; i < k; i++) buffer_entrada[i] = BUFFER_ENTRADA_criar(nome_particoes[i], qtd_registro_entrada);
  Buffer *buffer_saida = BUFFER_SAIDA_criar(nome_saida, bytes_buffer_saida/sizeof(ITEM_VENDA));

  printf("\n3 - Ordenando arquivos, por favor aguarde...");
  //FAÇO INTERCALAÇÃO NOS BUFFER DE ENTRADA REALIZANDO DUMP NO DE SAIDA
  intercalacao_k_vias(buffer_entrada, buffer_saida, k);

  //DESALOCO TODOS OS DADOS
  BUFFER_deletar(buffer_saida);
  for(int i = 0; i < k; i++){
    BUFFER_deletar(buffer_entrada[i]);
    remove(nome_particoes[i]);
    free(nome_particoes[i]);  
  }
  free(buffer_entrada);
  free(nome_particoes);

  printf("\n====================================");
}

int isSaidaOrdenada (char *nome_arquivo) {
  ITEM_VENDA item_anterior[1];
  ITEM_VENDA item_atual[1];

  FILE *arq = fopen(nome_arquivo, "rb");

  if(arq == NULL) {
    printf("Impossível abrir o arquivo!\n");
    return -1;
  }

  fread(item_anterior, sizeof(ITEM_VENDA), 1, arq);
  
  while(!feof(arq)) {
    fread(item_atual, sizeof(ITEM_VENDA), 1, arq);
    if (item_atual[0].id < item_anterior[0].id) return 0;


    *item_anterior = *item_atual;
  }

  return 1;
}
