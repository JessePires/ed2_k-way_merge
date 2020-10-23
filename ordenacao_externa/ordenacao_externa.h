#pragma once

/*FUNÇÃO QUE REALIZA ORDENAÇÃO DE UM ARQUIVO GRANDE COM LIMITANTE DE MEMORIA
*@param: entrada = arquivo que queremos ordenar
*@param: bytes_registros = quantidade máxima de memoria que podemos utilizar
*@param: bytes_buffer_saida = quantidade de bytes disponiveis para buffer de saida
*/
void ordenacao_externa(char *entrada, unsigned long int bytes_registros, unsigned long int bytes_buffer_saida, char *nome_saida);

/*FUNÇÃO VERIFICA SE ARQUIVO FINAL ESTÁ ORDENADO
*@param: nome_arquivo = arquivo que desejamos fazer a verificação
*@return: 1 caso ordenado e 0 caso contrario
*/
int isSaidaOrdenada (char *nome_arquivo);
