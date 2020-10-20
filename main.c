#include <stdio.h>
#include "big_file.h"
#include "particao/particao.h"

#define PK (1572864/5)/1024

int main(int argc, char** argv){
    printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
    gerar_array_iv("teste.dat", (1572864/5), 42);

    criarParticao("teste.dat", (1024*100));

    return 0;
}
