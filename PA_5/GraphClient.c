//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa5
//Note: was provided by professor, edited by me

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"


int main(int argc, char* argv[]){

   List  C = newList(); 
   Graph DG = NULL;
   Graph UG = NULL;

   // Build graph G 
   UG = newGraph(5);
   addEdge(UG, 1, 3);
   addEdge(UG, 2, 4);
   addEdge(UG, 1, 4);
   addEdge(UG, 4, 5);
   addEdge(UG, 1, 2);

   printGraph(stdout, UG);
   printf("Number of edges %d\n", getSize(UG));
   printf("Number of vertices %d\n", getOrder(UG));
   
   DG = newGraph(5);
   addArc(DG, 1, 2);
   addArc(DG, 2, 3);
   addArc(DG, 3, 4);
   addArc(DG, 4, 5);
   addArc(DG, 2, 1);


   printGraph(stdout, DG);
   Graph T = NULL;
   T = transpose(DG);
   printGraph(stdout, T);

   printf("Number of edges %d\n", getSize(DG));
   printf("Number of vertices %d\n", getOrder(DG));



   freeList(&C);
   freeGraph(&UG);
   freeGraph(&DG);

   return(0);
}