#pragma once

#include <stdint.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

/*FUNÇÃO GERADORA DE ARQUIVO
*@param: arquivo_saida = arquivo onde os dados serão armazenados
*@param: n_registros = quantidade de registros que o arquivo terá
*@param: seed = seed para gerar dados
*/
void gerar_array_iv(const char* arquivo_saida, unsigned int n_registros, int seed);