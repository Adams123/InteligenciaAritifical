#ifndef _HANOI_H_
#define _HANOI_H_

    #include "grafoo.h"

    void createStateSpace(Grafo*, int);
    int create_next_state(Grafo*, int, int*);
    void conect_nodes(Grafo*, int);

#endif // _HANOI_H_
