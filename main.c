#include <stdio.h>
#include <stdlib.h>
#include "big_file.h"
#include "buffer/buffer.h"
#include "particao/particao.h"
#include <math.h>

#define MB100 104857600
#define MB10 10485760

void intercalacao_k_vias(Buffer **entrada, Buffer *saida){

}

void ordenacao_externa(char *entrada, unsigned long int bytes_registros, unsigned long int bytes_buffer_saida, char *nome_saida){
  FILE *arq = fopen(entrada, "rb");
  fseek(arq, 0, SEEK_END);
  int e = ftell(arq);
  fclose(arq);
  
  int k = ceil((float)e/bytes_registros);
  unsigned long int qtd_registro_entrada = floor(((float)(bytes_registros-bytes_buffer_saida)/k)/1024);
  char **pk = criarParticao("teste.dat", k);

  //CRIANDO BUFFER
  Buffer **buffer_entrada = calloc(k, sizeof(Buffer*));
  for(int i = 0; i < k; i++) *buffer_entrada = criarBufferEntrada(pk[i], qtd_registro_entrada, NULL);
  Buffer *buffer_saida = criarBufferSaida(nome_saida, bytes_buffer_saida/1024);

  intercalacao_k_vias(buffer_entrada, buffer_saida);
  printf("TESTE");
}

int main(int argc, char** argv){
  printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
  // gerar_array_iv("teste.dat", (1572864/5), 42);
  
  ordenacao_externa("teste.dat", 104857600, 10485760, "saida.dat");


  teste_ordenacao_particao("p1.dat");

  return 0;
}
