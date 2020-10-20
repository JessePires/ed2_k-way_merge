#include <stdio.h>
#include "big_file.h"
<<<<<<< HEAD
#include "particao/particao.h"

#define PK (1572864/5)/1024

int main(int argc, char** argv){
    printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
    // gerar_array_iv("teste.dat", (1572864/5), 42);

    criarParticao("teste.dat", (1024*100));
=======

int main(int argc, char** argv){
    printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
    gerar_array_iv("teste.dat", (1572864/5), 42);
>>>>>>> 7224bc9a6a2c33462b48f97e57037c1e9ab8a41f

    return 0;
}
