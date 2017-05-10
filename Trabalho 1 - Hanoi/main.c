#include "hanoi.h"

int main(int argc, char argv[]){
    int n;
    Grafo *G;
    int v = 0;

    scanf("%d", &n);
    int size = pow(3,n);
    G = criaGrafo(size);

    createStateSpace(G,n);

    conect_nodes(G, n);

    iniciarDfs(G, size);

    bfs(G, 0, size);

    dijkstra(G,0,size-1,n);
    printf("Caminho para solução ideal usando A*:\n");
    find_path(0,size-1,parent,G, n);



    return 0;
}
