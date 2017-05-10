#include "lista.h"
#include<stdlib.h>

void cria(Lista *L) {//função que seta os poteiros de um nó(criação da lista)
     L->inicio=NULL;
     L->fim=NULL;
}

void finaliza(Lista *L) {//finaliza a lista
     no *p;
     p=L->inicio;
     while (p!=NULL) {
           L->inicio=L->inicio->prox;
           free(p);
           p=L->inicio;
     }
     L->fim=NULL;
}


void inserir(Lista *L, int x) {//o insere ordenado
     no *p;
     no *aux;
     no *anterior;

     anterior = L->inicio;
     aux = L->inicio;
     p=(no*) malloc(sizeof(no));
     p->valor = x;
     p->prox=NULL;
     if (L->inicio==NULL){
        L->inicio=p;
        L->fim = p;
     }
     else{
        while(aux != NULL && aux->valor < p->valor){
            anterior = aux;
            aux = aux->prox;
        }
        if(L->inicio == anterior && anterior->valor > p->valor){
           p->prox = anterior;
           L->inicio = p;
        }
        else{
           if(aux == NULL && L->inicio != anterior){
              p->prox = anterior->prox;
              anterior->prox = p;
              L->fim = p;
           }
           else{
             p->prox = anterior->prox;
             anterior->prox = p;
           }
        }
     }
}


void eliminar(Lista *L, int x) {//elimin um leemento da lista de adjacencia
     no *p, *aux;
     int teste=0;
     p=L->inicio;
     while ((p!=NULL) && (!teste)) {
           if (p->valor==x) {
              if (p==L->inicio)
                 L->inicio=L->inicio->prox;
              else if (p==L->fim) {
                   L->fim=aux;
                   L->fim->prox=NULL;
              }
              else aux->prox=p->prox;
              free(p);
           }
           else {
                aux=p;
                p=p->prox;
           }
     }
}


int tamanho(Lista *L) {//retorna o tamanho da lista
    no *p;
    int contador=0;

    p=L->inicio;
    while (p!=NULL) {
          contador++;
          p=p->prox;
    }
    return(contador);
}



int esta_na_lista(Lista *L, int x) {//procura se o elemento está na lista de adjacência
    no *p;

    p=L->inicio;
    while ((p!=NULL) && (p->valor!=x)) {
          p=p->prox;
    }

    if (p!=NULL) return 1;
    else return 0;
}



void imprimir(Lista *L) {//imprimi a lista de adjacência
     no *p;

     p=L->inicio;
     while (p!=NULL) {
           printf(" %d ",p->valor);
           p=p->prox;
     }
}

int *returnLista(Lista *L){//retorna um vetor com a a lista de adjacênccia do nó escolhido!
    int *v;
    v = (int*)malloc(sizeof(int)*tamanho(L));
    no *p,*aux;
    int i = 0;
    p = L->inicio;
    while(p != NULL && i < tamanho(L)){
       v[i] = p->valor;
       p = p->prox;
       i++;
    }

    return v;
}
