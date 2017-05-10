#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <math.h>
#include <string.h>
#define NULO -1
#define BRANCO -1
#define CINZA 0
#define PRETO 1

typedef struct bloco
{
    int valor;
    int flag;
    struct bloco *prox;
} no;

typedef struct
{
    no *inicio, *fim;
} Lista;

int* retornaLista(Lista*);
void cria(Lista*);
void finaliza(Lista*);
void inserir(Lista*,int);
void eliminar(Lista*, int);
int tamanho(Lista*);
int esta_na_lista(Lista*,int);
void imprimir(Lista*);

#endif // _LISTA_H_
