//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa4
//Note: was provided by professor, edited by me

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
   
   DG = newGraph(5);
   addArc(DG, 1, 2);
   addArc(DG, 2, 3);
   addArc(DG, 3, 4);
   addArc(DG, 4, 5);
   addArc(DG, 2, 1);

   BFS(DG, 1);
   getPath(P, DG, 5);
   printGraph(stdout, DG);
   printf("Number of edges %d\n", getSize(DG));
   printf("Number of vertices %d\n", getOrder(DG));
   printf("Shortest path from 1 to 5 is: ");
   printList(stdout, P);

   makeNull(UG);
   printf("Number of edges %d\n", getSize(UG));
   printf("Number of vertices %d\n", getOrder(UG));

   makeNull(DG);
   printf("Number of edges %d\n", getSize(DG));
   printf("Number of vertices %d\n", getOrder(DG));

   freeList(&C);
   freeList(&P);
   freeList(&E);
   freeGraph(&UG);
   freeGraph(&DG);

   return(0);
}