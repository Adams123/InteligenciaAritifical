#include "Fila.h"

void criarFila(Fila *F) {

     F->fim = NULL;
     F->inicio = NULL;

}

void inserirFila(Fila *F, int id) {

     NoFila *no;

     no = (NoFila*) malloc(sizeof(NoFila));
     no->id = id;
     no->prox = NULL;

     if (F->inicio == NULL)    F->inicio = no;
     else                      F->fim->prox = no;


     F->fim = no;

}


int removerFila(Fila *F) {

     NoFila *no;
     int id;

     no = F->inicio;
     F->inicio = no->prox;

     if (F->inicio == NULL) F->fim = NULL;

     id = no->id;

     free(no);

     return id;
}



void imprimirFila(Fila *F) {

     NoFila *no;

     no = F->inicio;

     while (no != NULL) {

           printf("%d ", no->id);
           no = no->prox;
     }

     printf("\n");
}

int filaVazia(Fila *F) {

     return (F->inicio == NULL && F->fim == NULL) ? 1 : 0;
}

