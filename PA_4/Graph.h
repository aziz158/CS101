//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa4

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define NIL 0
#define INF -1

typedef struct GraphObj* Graph;

Graph newGraph(int n);
void freeGraph(Graph* pG);
int getSize(Graph G);
int getOrder(Graph G); 
int getSource(Graph G); 
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void makeNull(Graph G);
void getPath(List L, Graph G, int u);
void printGraph(FILE* out, Graph G);

void addEdge(Graph G, int u, int v); 
void addArc(Graph G, int u, int v); 
void BFS(Graph G, int s);

#endif