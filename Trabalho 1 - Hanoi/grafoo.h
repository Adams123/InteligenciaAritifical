#ifndef _GRAFOO_H_
#define _GRAFOO_H_

#include "Pilha.h"
#include <limits.h>
#include <float.h>
#include "Fila.h"

#define HEURISTIC_1 0
#define HEURISTIC_2 1
#define INF 99999

typedef struct grafo
{
    int key[20];
    int flag;
    Lista *L;
} Grafo;

int *pesos;
int *parent;
//    int movimentos=0;

Grafo* criaGrafo(int);
void adicionaAresta(Grafo*,int,int);
void printaGrafo(Grafo*,int);
Grafo* transpoeGrafo(Grafo*,int);
void removeAresta(Grafo*,int,int);
int search_Nodes(Grafo*, int*, int);
void find_path(int start, int goal, int *dist, Grafo *G, int tam);

#endif // _GRAFOO_H_
