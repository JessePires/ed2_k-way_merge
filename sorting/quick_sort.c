#include "quick_sort.h"

static void troca (ITEM_VENDA *itens, unsigned long int i, unsigned long int j) {
  ITEM_VENDA element = itens[i];
  itens[i] = itens[j];
  itens[j] = element;
}

static int partition (ITEM_VENDA *itens, unsigned long int p, unsigned long int r) {
  ITEM_VENDA pivot;
  unsigned long int i, j;
  
  pivot = itens[r];
  i = p-1;

  for (j = p; j < r; j++) {
    if (itens[j].id <= pivot.id) {
      i++;
      troca(itens, i, j);
    }
  }

  troca(itens, i+1, r);
  return i+1;
}

void quickSort (ITEM_VENDA *itens, unsigned long int left, unsigned long int right) {
  unsigned long int q;

  while (left < right) {
    q = partition(itens, left, right);

    if (q - left < right - q) {
      quickSort(itens, left, q-1);
      right = q + 1;
    } else {
      quickSort(itens, q+1, right);
      right = q - 1;
    }
  }
}
