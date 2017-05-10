#include"grafoo.h"

int movimentos=0;

Grafo* criaGrafo(int tam) //função que cria o grafo!
{
    Grafo *G;
    int i;

    G = (Grafo*)malloc(sizeof(Grafo)*tam);
    for(i = 0; i < tam; i++)
    {
        G[i].L = (Lista*)malloc(sizeof(Lista));
        cria(G[i].L);
        G[i].flag = BRANCO;
    }
    return G;
}

int search_Nodes(Grafo* G, int* state, int n)
{
    int size = pow(3,n);
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < n ; j++)
        {
            if(G[i].key[j] != state[j])
                break;
            else if( j == n-1 )
                return i;
        }
    }
    return 0;
}

void adicionaAresta(Grafo *G, int first, int second) //função que adiciona a aresta ao grafo valorado!(caso quiser fazer um grafo não valorado(não é um digrafo) é só você colocar embaixo do inserir)
{
    inserir(G[first].L,second);
    //coloque  inserir(G[second].L,first); aqui para que o grafo nao seja valorado.

}

void printaGrafo(Grafo *G, int n) //printa o grafo existente a partir das suas listas de adjacencia
{
    int i,j;
    int tam = pow(3,n);

    for(i = 0; i < tam; i++)
    {
        printf("n: %d  ,",i);
        for(j = 0; j < n; j++)
            printf(" %d",G[i].key[j]);

        printf(" L: ");
        imprimir(G[i].L);
        printf("\n");
    }
}

Grafo* transpoeGrafo(Grafo *G,int TAM) //função que transpoe um grafo
{
    int i;
    no *p;
    Grafo *GT;
    GT = criaGrafo(TAM);
    for(i = 0; i < TAM; i++)
    {
        if(tamanho(G[i].L) != 0)
        {
            p = G[i].L->inicio;
            while(p!= NULL)
            {
                inserir(GT[p->valor].L,i);
                eliminar(G[i].L,p->valor);
                p = p->prox;
            }
        }
    }
    return G;
}
void removeAresta(Grafo *G,int vertice,int adjacente) // função que remove uma aresta do grafo se for grafo valorado coloque embaxo do eliminar(G[vertice].L,adjacente); um eliminar(G[adjacente].L,vertice);
{
    eliminar(G[vertice].L,adjacente);
}


void dfs(Grafo *G, int v, int pai[], int cor[], int inicioProc[], int *timestamp)
{
    int *viz;
    int i;

    cor[v] = CINZA;
    inicioProc[v] = (*timestamp)++;

    viz =  returnLista(G[v].L);
    for(i = 0; i < tamanho(G[v].L); i++)
    {
        if (cor[*(viz + i)] == BRANCO)
        {
            pai[*(viz + i)] = v;
            dfs(G, *(viz + i), pai, cor, inicioProc, timestamp);
        }
    }
    cor[v] = PRETO;
}


void iniciarDfs(Grafo *G, int tam)
{

    int pai[tam];
    int cor[tam];
    int inicioProc[tam];
    int timestamp = 0;

    int v;

    for (v = 0; v < tam; v++)
    {
        pai[v] = NULO;
        cor[v] = BRANCO;
        inicioProc[v] = NULO;
    }

    for (v = 0; v < tam; v++)
        if (cor[v] == BRANCO)
            dfs(G, v, pai, cor, inicioProc, &timestamp);

    printf("DFS: %d estados vizitados\n", inicioProc[tam-1]);
}



void bfs(Grafo *G, int s, int tam)
{

    int cor[tam];
    int inicioProc[tam];
    int pai[tam];
    int dista[tam];

    int timestamp = 0;

    int v, u, i;

    int *viz;

    for (v = 0; v < tam; v++)
    {
        cor[v] = BRANCO;
        inicioProc[v] = NULO;
        pai[v] = NULO;
    }

    Fila F;
    criarFila(&F);

    inserirFila(&F, s);

    dista[s] = 0;
    cor[s] = CINZA;
    inicioProc[s] = timestamp++;


    while (!filaVazia(&F))
    {
        v = removerFila(&F);

        viz = returnLista(G[v].L);

        for(i = 0; i < tamanho(G[v].L); i++)
        {
            u = *(viz + i);
            if (cor[u] == BRANCO)
            {
                cor[u] = CINZA;
                inicioProc[u] = timestamp++;

                pai[u] = v;
                dista[u] = dista[v] + 1;

                inserirFila(&F, u);
            }
        }
        cor[v] = PRETO;
    }
    printf("BFS: %d estados vizitados\n", inicioProc[tam-1]);
}

void calculaPesos(Grafo *G, int tam) //calcula pesos baseado na heurística explicada no relatório
{
    int size=pow(3,tam);
    int i, j;
    pesos=(int*)malloc(sizeof(int)*size);
    int peso=0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(G[i].key[j]!=3)
                peso++;
        }
        pesos[i]=peso;
        peso=0;
    }
}

void dijkstra(Grafo *G, int start, int target, int tam)		/* WAS prim(g,start) */
{
    calculaPesos(G,tam);
    int i,j;			/* contadores */
    int size = pow(3,tam);
    int intree[size];		/* o vértice já está na árvore? */
    int distance[size];		/* distancia que o vértice está do início*/
    int v;				/* vertice atual a ser processado */
    int w;				/* candidato a próximo vertice*/
    int weight;			/* peso da aresta*/
    int dist;			/* melhor distancia atual do início */
    no *aux;            /* auxiliar para percorrer as listas de adjacências*/
    parent=(int*)malloc(sizeof(int)*size);
    movimentos = 0;
    for (i=0; i<size; i++) //inicialização de valores
    {
        intree[i] = 0;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;
    while (intree[v] == 0) //enquanto não percorrer tudo
    {
        intree[v] = 1;
        aux=G[v].L->inicio;
        for (i=0; i<tamanho(G[v].L); i++) //percorrendo toda a vizinhança de v
        {
            w = aux->valor;
            aux=aux->prox;
            weight = pesos[v] + movimentos; //peso para ser comparado
            if (distance[w] > (distance[v]+weight)) //verifica se o peso do vizinho é menor
            {
                distance[w] = distance[v]+weight;
                parent[w] = v;
            }
            if(v==start) break;
        }
        movimentos++;
        v = 0;
        dist = INT_MAX;
        for (i=0; i<size; i++)          //seta o vetor de distancias para o menor peso
            if ((intree[i] == 0) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
        if(target == v) break;
    }
    movimentos=0; //zerando movimentos para usar como contador no find_path
}

void find_path(int start, int goal, int *dist, Grafo *G, int tam)
{

    if ((start == goal) || (goal== -1)) //se chegou no alvo ou se o alvo não existe mais
    {
        printf("%d: ", movimentos);
        int i;

        for(i=0;i<tam;i++)
            printf("%d ",G[start].key[i]);
            printf("\n");
    }

    else
    {
        find_path(start,parent[goal],parent, G, tam); //chama recursivo para o próximo
        printf("%d: ", movimentos);
        int i;

        for(i=0;i<tam;i++)
            printf("%d ",G[goal].key[i]);
            printf("\n");
    }
    movimentos++;
}
