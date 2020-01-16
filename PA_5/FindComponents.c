//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"

#define MAX_LEN 1000

int main(int argc, char * argv[]){


    FILE *in, *out;
    //int *line;
    
    // check command line for correct number of arguments
    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    
    // open files for reading and writing
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    if( in==NULL ){
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }

    if( out==NULL ){
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }

    int size;
    fscanf(in, "%d", &size);
    Graph G = newGraph(size);


    int val1, val2;
    fscanf(in, "%d %d" , &val1, &val2);
    addArc(G, val1, val2);
	while(val1 != 0 && val2 != 0)
	{
		fscanf(in, "%d %d" , &val1, &val2);
		if(val1 == 0 || val2 == 0) break;
		addArc(G, val1, val2);
	}

	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G);
	fprintf(out, "\n");

	List L = newList();
	int i;
	for(i=1; i<=size; i++) append(L, i);
	Graph T = NULL; 
	T = transpose(G);
	DFS(G, L);
	DFS(T, L);
	int z, j, n = 0;
	for(z = 1; z<=getOrder(T); z++)
	{
		if(getParent(T, z) == 0)
		{
			n++;
		}
	}

	fprintf(out, "G contains %d strongly connected components:\n", n);


	List *N = malloc((n+1)*sizeof(List));

	for(j = 1; j <= n; j++)
	{
		N[j] = newList();
	}

	int l = n+1, h = 0, b, a;

	for(moveFront(L); index(L) >= 0; moveNext(L))
	{
		h = get(L);
		if(getParent(T, h) == 0) l--;
		append(N[l], h);
	}

	for(b = 1; b <= n; b++)
	{
		fprintf(out, "Component %d: ", b);
		printList(out, N[b]);
	}

	for(a = 1; a <= n; a++)
	{
		freeList(&N[a]);
	}


    //free(*line);
    fclose(in);
    fclose(out);

}