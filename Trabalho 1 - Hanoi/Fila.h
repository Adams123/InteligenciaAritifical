#include <stdlib.h>
#include <stdio.h>

typedef struct NoFila {
        int id;
        struct NoFila *prox;
} NoFila;

typedef struct {
        NoFila *inicio;
        NoFila *fim;
} Fila;

void criarFila(Fila*);

void inserirFila(Fila*, int);

int removerFila(Fila*);

void imprimirFila(Fila*);

int filaVazia(Fila*);
