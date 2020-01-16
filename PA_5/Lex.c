//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"

#define MAX_LEN 1000

int main(int argc, char * argv[]){
    
    int n = 0, count=0;
    FILE *in, *out, *in2;
    char line[MAX_LEN];
    char line1[MAX_LEN];
    char* string[MAX_LEN];
    
    // check command line for correct number of arguments
    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    
    // open files for reading and writing
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    in2 = fopen(argv[1], "r");
    if( in==NULL ){
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }

    if( out==NULL ){
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }
    
    /* read each line of input file, then count and print tokens */
    while( fgets(line, MAX_LEN, in) != NULL)  {
        count++;
    }
    fclose(in);

    int j;
    for(j = 0; j < count; j++)
    {
         string[j] = malloc(count*(sizeof(char*)));   
    }    

    while( fgets(line1, MAX_LEN, in2) != NULL)
    {
        strcpy(string[n], line1);
        n++;
    }
    strcat(string[count-1], "\n");
    
    
    List L = newList();
    append(L, 0);
    int k;
    for (k = 1; k < count; k++)
    {
        moveFront(L);
        int v = get(L);
        while(strcmp(string[k], string[v]) >= 0)
        {
            moveNext(L);
            if(index(L) == -1)
            {
                append(L, k);
                break;
            }
            v = get(L);
        }
        if(index(L) >= 0)
        {
            insertBefore(L, k);
        }
    }

    moveFront(L);
    int i;
    for(i = 0; i < count; i++)
    {
        fprintf(out, "%s", string[get(L)]);
        moveNext(L);
    }

    int z;
    for(z = 0; z < count; z++)
    {
         free(string[z]);   
    }
    free(*string);    


    /* close files */
    fclose(in2);
    fclose(out);
    
    return(0);
}
