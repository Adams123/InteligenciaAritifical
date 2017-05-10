#ifndef _PILHA_H_
#define _PILHA_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lista.h"
    typedef struct ElementoLista {
        Lista *dado;
        struct ElementoLista *proximo;
    }Elemento;

    typedef struct ListaDetectada
    {
        Elemento *inicio;
        int tamanho;
    } Pilha;

    int push (Pilha * monte, Lista *dado);
    int pop (Pilha * monte);
    void inicializacao (Pilha *monte);
    void exibe (Pilha * monte);
    void limpa_pilha(Pilha * monte);

#endif // _PILHA_H_
