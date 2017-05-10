#include "Pilha.h"

void inicializacao (Pilha *monte)
{
    monte->inicio = NULL;
    monte->tamanho = 0;
}

int push (Pilha * monte, Lista *dado)
{
    Elemento *novo_elemento;
    if ((novo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((novo_elemento->dado = (Lista *) malloc (sizeof (Lista)))== NULL)
        return -1;
    novo_elemento->dado = dado;
    novo_elemento->proximo = monte->inicio;
    monte->inicio = novo_elemento;
    monte->tamanho++;
}

int pop (Pilha * monte)
{
    Elemento *remov_elemento;
    if (monte->tamanho == 0)
        return -1;
    remov_elemento = monte->inicio;
    monte->inicio = monte->inicio->proximo;
    free (remov_elemento->dado);
    free (remov_elemento);
    monte->tamanho--;
    return 0;
}


void exibe (Pilha * monte)
{
    Elemento *corrente;
    int i;
    corrente= monte->inicio;
    for(i=0; i<monte->tamanho; ++i)
    {
        printf("%d\n", corrente->dado->inicio->valor);
        corrente= corrente->proximo;
    }
}

void limpa_pilha(Pilha * monte)
{
    int i;
    while(monte->tamanho>0)
        pop(monte);
    monte->inicio=NULL;
}
