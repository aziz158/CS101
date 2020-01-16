//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa4

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

#define NIL 0
#define INF -1


typedef struct GraphObj{
 	List* ListArray;
    int NV;              // Number of Vertices
    int NE;              // Number of Edges
    int* color;
    int* parent;
    int* distance;
    int source;


} GraphObj;



Graph newGraph(int n)
{
	Graph G;
	G = malloc(sizeof(GraphObj));
	G->NV = n;
	G->NE = 0;
	G->source = 0;
	int i;
	G->color = calloc(n+1, sizeof(int));
	G->parent = calloc(n+1, sizeof(int));
	G->distance = calloc(n+1, sizeof(int));
	G->ListArray = malloc((n+1)*sizeof(List));
	

	for(i = 1; i <= n; i++)
	{
		G->ListArray[i] = newList();
		G->color[i] = 0;
		G->parent[i] = NIL;
		G->distance[i] = INF;
	}
	return G;
}

void freeGraph(Graph* pG)
{
	if(pG != NULL && *pG != NULL)
	{
		int i;
		for(i = 1; i <= getOrder(*pG); i++)
		{
			freeList(&(*pG)->ListArray[i]);
		}

		free((*pG)->ListArray);
		free((*pG)->color);
		free((*pG)->distance);
		free((*pG)->parent);
		free(*pG);
		*pG = NULL;
	}
}

int getSize(Graph G)
{
	return G->NE;
}

int getOrder(Graph G)
{
	return G->NV;
} 

int getSource(Graph G)
{
	return G->source;
}

int getParent(Graph G, int u)
{
	return G->parent[u];
}

int getDist(Graph G, int u)
{
	return G->distance[u];
}

void makeNull(Graph G)
{
	int i;
	for(i = 1; i <= getOrder(G); i++)
	{
		clear(G->ListArray[i]);
	}
	G->NE = 0;
	G->source = 0;
}

void getPath(List L, Graph G, int u)
{
	if(G->source == u)
	{
		append(L, u);
	}
	else
	{
		int x;
		x = getParent(G, u);
		if(x == NIL || x == INF)
		{ 
			append(L, 0);
		}
		else
		{
			getPath(L, G, x);
			append(L, u);
		}
	}
}

void addEdge(Graph G, int u, int v)
{
	if(isEmpty(G->ListArray[u])) append(G->ListArray[u], v);
	else
	{
	moveBack(G->ListArray[u]);
    while (index(G->ListArray[u]) > -1 && get(G->ListArray[u]) > v)
        moveNext(G->ListArray[u]);
    if (index(G->ListArray[u]) == -1)
        prepend(G->ListArray[u], v);
    else
        insertAfter(G->ListArray[u], v);
    
    }
    

    if(isEmpty(G->ListArray[v])) append(G->ListArray[v], u);
    else
    {
    moveBack(G->ListArray[v]);
    while (index(G->ListArray[v]) > -1 && get(G->ListArray[v]) > u)
        moveNext(G->ListArray[v]);
    if (index(G->ListArray[v]) == -1)
        prepend(G->ListArray[v], u);
    else
        insertAfter(G->ListArray[v], u);
	}

	G->NE++;
}

void addArc(Graph G, int u, int v)
{
	if(isEmpty(G->ListArray[u])) append(G->ListArray[u], v);
	else
	{
	moveBack(G->ListArray[u]);
    while (index(G->ListArray[u]) > -1 && get(G->ListArray[u]) > v)
        moveNext(G->ListArray[u]);
    if (index(G->ListArray[u]) == -1)
        prepend(G->ListArray[u], v);
    else
        insertAfter(G->ListArray[u], v);
    
    }
	G->NE++;
} 

//Color: 0 = white, 1 = gray, 2 = black

void BFS(Graph G, int s)
{
	int u, v, i;
	for (i = 0; i <= getOrder(G); i++)
	{
		G->color[i] = 0;
		G->parent[i] = NIL;
		G->distance[i] = INF;
	}
	G->source = s;
	G->color[s] = 1;
	G->distance[s] = 0;
	G->parent[s] = NIL;
	List L = newList();
	append(L, s);
	while(!isEmpty(L))
	{
		moveFront(L);
		u = get(L);
		deleteFront(L);
		moveFront(G->ListArray[u]);
		while(index(G->ListArray[u]) != -1)
		{
			v = get(G->ListArray[u]);
			if(G->color[v] == 0)
			{
				G->color[v] = 1;
				G->distance[v] = G->distance[u]+1;
				G->parent[v] = u;
				append(L, v);
			}
			moveNext(G->ListArray[u]);
		}
		G->color[u] = 2;
	}
	freeList(&L);

}


void printGraph(FILE* out, Graph G)
{
	int i;
	for(i = 1; i <= getOrder(G); i++)
	{
		if(!(isEmpty(G->ListArray[i])))
		{
			printf("%d", i);
			printf(": ");
			printList(stdout, G->ListArray[i]);
		}
	}
}





