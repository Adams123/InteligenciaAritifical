#include "hanoi.h"

int heuristic_peg(int state[], int n){
    int value = 0;
    int i;

    for(i = 0; i < n; i++ ){
        if(state[i] != 3)
            value++;
    }
    return value;
}
int heuristic_position(int state[], int n){
    int value = 0;
    int i;

    //se o maior bloco nao esta no pino 3
    if(state[n-1]!=3)
        value++;

    for(i = 0; i < n; i++ ){
        // se o bloco menor nao esta em cima do bloco correto
        if(state[i] != state[i+1])
            value++;
    }
    return value;
}

void createStateSpace(Grafo *G, int n)
{
    int state[20];
    int i,next = 1,pos = 0;
    //cria estado inicial do problema
    //todos os blocos estao no primeiro pino
    for(i = 0; i < n; i++)
        state[i] = 1;

    while(next == 1)
    {
        for(i = 0; i < n; i++)
            G[pos].key[i] = state[i];

        pos++;
        next = create_next_state(G, n, state);

    }

}
// cria um segundo estado a partir de um estado de entrada
int create_next_state(Grafo *G, int n, int *state)
{
    int j;

    if(state[n-1] < 3)
    {
        state[n-1]++;
        return 1;
    }

    for(j = n - 2; j >= 0; j--)
    {
        state[j + 1] = 1;

        if(state[j] < 3)
            break;
    }

    if(j < 0)
        return 0;

    state[j]++;

    return 1;
}

//cria as arestas do grafp
//uma aresta significa que ha um movimento permitido entre dois estados
void conect_nodes(Grafo *G, int n)
{
    int i,j, k, l;
    int size = pow(3,n);
    int n1, n2;
    int aux[20];

    for(i = 0; i< size; i++)
    {
        for(j = 0; j < n; j++)
        {
            aux[j] =  G[i].key[j];
        }
        n1 = search_Nodes(G, aux, n);

        for(j = 1; j<=3; j++)
        {
            if(aux[n-1] != j)
            {
                aux[n-1] = j;
                n2 = search_Nodes(G, aux, n);
                adicionaAresta(G, n1, n2);
                aux[n-1] = G[i].key[n-1];
            }
        }

        for(j = n-2; j>= 0; j--)
        {
            for(k = j+1; k < n; k++)
                if(aux[j] == aux[k])
                    break;

            if(k == n)
            {
                for(l = 1; l<=3; l++)
                {
                    if(aux[j] != l && aux[n-1] != l)
                    {
                        aux[j] = l;
                        n2 = search_Nodes(G, aux, n);
                        adicionaAresta(G, n1, n2);
                        aux[j] = G[i].key[j];
                    }
                }
                break;
            }
        }

    }

}
