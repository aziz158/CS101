#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"


int main(int argc, char* argv[]){
  
   List  C = newList(); 
   List  P = newList(); 
   List  E = newList(); 
   Graph DG = NULL;
   Graph UG = NULL;

   // Build graph G 
   UG = newGraph(5);
   addEdge(UG, 1, 3);
   addEdge(UG, 2, 4);
   addEdge(UG, 1, 4);
   addEdge(UG, 4, 5);
   addEdge(UG, 1, 2);

   BFS(UG, 1);
   getPath(C, UG, 5);
   printGraph(stdout, UG);
   printf("Number of edges %d\n", getSize(UG));
   printf("Number of vertices %d\n", getOrder(UG));
   printf("Shortest path from 1 to 5 is: ");
   printList(stdout, C);

   makeNull(UG);
   
   freeList(&C);
   freeList(&P);
   freeList(&E);
   freeGraph(&UG);
   freeGraph(&DG);

   return(0);
}