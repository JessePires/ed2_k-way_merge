#pragma once
#include "../big_file/big_file.h"
#include <stdio.h>
#include <stdlib.h>

#define STEPOFREAD 10

typedef struct Buffer{
  ITEM_VENDA *vet;
  int maxsize;
  int proximo;
  FILE *arq;
} Buffer;

/*FUNÇÃO QUE CRIA O BUFFER DE ENTRADA
*@param: arquivo = nome do arquivo do qual o buffer receberá registros
*@param: qtdRegistros = quantidade máxima de registros que o buffer suporta
*@return: ponteiro para o buffer
*/
Buffer* BUFFER_ENTRADA_criar(char* arquivo, unsigned long int qtdRegistros);

/*FUNÇÃO QUE FAZ COM QUE O ÍNDICE ARMEZENADO NA ESTRUTURA PASSE A SER O INDICE DO PRÓXIMO REGISTRO
*@param: buffer = ponteiro para o buffer
*@return: um inteiro que é o indice da próxima posição do vetor
*/
int BUFFER_ENTRADA_proximo(Buffer* buffer);

/*FUNÇÃO QUE CONSOME UM ELEMENTO DO BUFFER
*@param: buffer = ponteiro para o buffer
*@param: i = posição do elemento a ser consumido
*@return: o elemento do tipo ITEM_VENDA consumido
*/
ITEM_VENDA* BUFFER_ENTRADA_consumir(Buffer* buffer, int i);

/*FUNÇÃO QUE VERIFICA SE TODOS OS REGISTROS DO ARQUIVO JÁ FORAM CONSUMIDOS
*@param: buffer = ponteiro para o buffer
*@return: 1 se todos os registros foram consumidos e 0 caso contrário
*/
int BUFFER_ENTRADA_vazio(Buffer *buffer);

/*FUNÇÃO QUE VERIFICA SE O VETOR DO BUFFER JÁ FOI TOTALMENTE VARRIDO
*@param: buffer = ponteiro para o buffer
*@return: 1 se o vetor foi totalmente varrido e 0 caso contrário
*/
int BUFFER_ENTRADA_bufferVazio(Buffer *buffer);

/*FUNÇÃO QUE CARREGA NOVOS REGISTROS PARA O BUFFER
*@param: buffer = ponteiro para o buffer
*/
void BUFFER_ENTRADA_reencher(Buffer* buffer);


/*FUNÇÃO QUE CRIA O BUFFER DE SAÍDA
*@param: arquivo = nome do arquivo do qual o buffer receberá registros
*@param: qtdRegistros = quantidade máxima de registros que o buffer suporta
*@return: ponteiro para o buffer
*/
Buffer* BUFFER_SAIDA_criar(char* arquivo, unsigned long int qtdRegistros);

/*FUNÇÃO QUE INSERE UM NOVO REGISTRO NO BUFFER DE SAÍDA
*@param: buffer = ponteiro para o buffer
*@param: item = item a ser inserido
*/
void BUFFER_SAIDA_inserirRegistro (Buffer *buffer, ITEM_VENDA *item);

/*FUNÇÃO QUE DESPEJA OS REGISTROS NO ARQUIVO DE SAÍDA
*@param: buffer: ponteiro para o buffer 
*/
void BUFFER_SAIDA_despejar (Buffer *buffer);

/*FUNÇÃO QUE DELETA (OU DESTRÓI) UM BUFFER (SEJA ELE DE ENTRADA OU DE SAÍDA)
*@param: buffer = ponteiro para o buffer
*/
void BUFFER_deletar(Buffer *buffer);
