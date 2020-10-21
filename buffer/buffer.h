#pragma once
#include "../big_file.h"
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

#define STEPOFREAD 10
=======
>>>>>>> c209dcc38a4aa08811dca5255aca99918c46fe21

typedef struct Buffer{
  ITEM_VENDA *vet;
  int maxsize;
  int proximo;
  FILE *arq;
} Buffer;

<<<<<<< HEAD
Buffer* criarBuffer(char* arquivo);
void deletarBuffer(Buffer *buffer);
=======
Buffer* criarBuffer(char* arquivo, int qtdRegistros);
void deletarBugger(Buffer *buffer);

int proximoBuffer(Buffer* buffer);
ITEM_VENDA* consomeBuffer(Buffer* buffer, int i);
int vazioBuffer(Buffer* buffer); 
>>>>>>> c209dcc38a4aa08811dca5255aca99918c46fe21
