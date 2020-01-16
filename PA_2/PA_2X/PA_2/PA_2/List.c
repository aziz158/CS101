//
//  List.c
//
//
//  Created by Aziz on 4/15/19.
//

#include "List.hpp"


//--------------------------------

typedef struct NodeObj{
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj{
    Node head;
    Node tail;
    Node cursor;
    int length;
    int index;
} ListObj;

//---------------------------------

Node newNode(int data){
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->next = NULL;
    N->prev = NULL;
    return(N);
}

List newList(void)
{
    List L;
    L = malloc(sizeof(ListObj));
    L->head = NULL;
    L->tail = NULL;
    L->cursor = NULL;
    L->length = 0;
    L->index = -1;
    return(L);
    
}

void freeNode(Node* pN){
    if(pN != NULL && *pN != NULL){
        free(*pN);
        *pN = NULL;
    }
}

void freeList(List* pL)
{
    if(pL != NULL && *pL!= NULL)
    {
        int i;
        for(i = 0; i< length(pL); i++)
        {
            moveFront(pL);
            delete(pL);
        }
        free(*pL);
        *pL = NULL;
    }
}

//-------------------------------------
int isEmpty(List L){
    if(L == NULL)
    {
        printf("List Error: calling isEmpty() on NULL List reference");
        exit(1);
    }
    
    return(L->length == 0);
}

int length(List L){
    
    if(L == NULL)
    {
        printf("List Error: calling length() on NULL List reference");
        exit(1);
    }
    
    return(L->length);
}

int index(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling index() on NULL List reference");
        exit(1);
    }
    
    return(L->index);
}

int front(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling front() on NULL List reference");
        exit(1);
    }
    
    if( isEmpty(L) ){
        printf("List Error: calling front() on an empty List\n");
        exit(1);
    }
    
    return(L->head->data);
}

int back(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling back() on NULL List reference");
        exit(1);
    }
    
    if( isEmpty(L) ){
        printf("List Error: calling back() on an empty List\n");
        exit(1);
    }
    
    return(L->tail->data);
}

int get(List L)
{
    if(L == NULL || L->index < 0)
    {
        printf("List Error: calling get() on NULL List reference");
        exit(1);
    }
    
    return L->cursor->data;
}

//-----------------------------------------------

void prepend(List L, int data)
{
    Node N = newNode(data);
    
    if(L == NULL)
    {
        printf("List Error: calling prepend() on NULL List reference");
        exit(1);
    }
    
    if(isEmpty(L))
    {
        L->head = N;
        L->tail = N;
        //N->next = NULL;
        //N->prev = NULL;
    } else {
        N->next = L->head;
        //N->prev = NULL;
        L->head->prev = N;
        L->head = N;
    }
    
    if(L->index != -1){L->index += 1;}
    
    L->length++;
    
}

void append(List L, int data)
{
    Node N = newNode(data);
    
    if(L == NULL)
    {
        printf("List Error: calling append() on NULL List reference");
        exit(1);
    }
    
    if(isEmpty(L))
    {
        L->head = N;
        L->tail = N;
    } else {
        N->prev = L->tail;
        L->tail->next = N;
        L->tail = N;
    }
    L->length++;
}



void moveFront(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling moveFront() on NULL List reference");
        exit(1);
    }
    
    if(!isEmpty(L))
    {
        L->cursor = L->head;
        L->index = 0;
    }
}

void moveBack(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling moveBack() on NULL List reference");
        exit(1);
    }
    
    if(!isEmpty(L))
    {
        L->cursor = L->tail;
        L->index = L->length - 1;
    }
}

void movePrev(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling movePrev() on NULL List reference");
        exit(1);
    }
    
    if(L->index != -1)
    {
        if(L->cursor == L->head)
        {
            L->index = -1;
            L->cursor = NULL;
        }
        else
        {
            L->cursor = L->cursor->prev;
            L->index = L->index - 1;
        }
    }
}

void moveNext(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling moveNext() on NULL List reference");
        exit(1);
    }
    
    if(L->index != -1)
    {
        if(L->cursor == L->tail)
        {
            L->index = -1;
            L->cursor = NULL;
        }
        else
        {
            L->cursor = L->cursor->next;
            L->index = L->index + 1;
        }
    }
}


//-------------------------------------------------------------
void printList(FILE* out, List L)
{
    Node temp = NULL;
    
    if(L == NULL)
    {
        printf("List Error: calling printList() on NULL List reference \n");
        exit(1);
    }
    
    for(temp = L->head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    
    printf("\n");
}


int equals(List A, List B)
{
    int eq = 0;
    Node temp1 = NULL;
    Node temp2 = NULL;
    
    if( A==NULL || B==NULL )
    {
        printf("List Error: calling equals() on NULL List reference\n");
        exit(1);
    }
    
    if(A->length != B->length)
        eq = 0;
    else
    {
        eq = 1;
        temp1 = A->head;
        temp2 = B->head;
        while (eq == 1 && temp1 != NULL)
        {
            eq = (temp1->data == temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return eq;
    
}

List copyList(List L)
{
    
    List tempList = newList();
    Node tempNode = NULL;
    tempNode = L->head;
    while (tempNode != NULL)
    {
        append(tempList, tempNode->data);
        tempNode = tempNode->next;
    }
    
    return tempList;
}

void insertBefore(List L, int data)
{
    if(L == NULL || L->index == -1)
    {
        printf("List Error: calling insertBefore() on NULL List reference \n");
        exit(1);
    }
    
    Node N = newNode(data);
    L->length += 1;
    
    if(L->cursor == L->head)
    {
        N->next = L->cursor;
        N->prev = NULL;
        L->cursor->prev = N;
        L->head = N;
        L->index +=1;
    }
    else
    {
        N->next = L->cursor;
        N->prev = L->cursor->prev;
        L->cursor->prev->next = N;
        L->cursor->prev = N;
        if(L->cursor == L->tail)
        {L->index = L->length - 1; }
        else {L->index += 1;}
    }
}

void insertAfter(List L, int data)
{
    if(L == NULL)
    {
        printf("List Error: calling insertAfter() on NULL List reference \n");
        exit(1);
    }
    
    Node N = newNode(data);
    if(L->cursor == L->tail)
    {
        N->prev = L->cursor;
        N->next = NULL;
        L->cursor->next = N;
        L->tail = N;
    }
    else
    {
        N->prev = L->cursor;
        N->next = L->cursor->next;
        L->cursor->next->prev = N;
        L->cursor->next = N;
        if(L->cursor == L->head)
        { L->index = 0;}
    }
    L->length += 1;
    
}

void delete(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling delete() on NULL List reference \n");
        exit(1);
    }
    
    if(L->length == 0 || L->index == -1)
    {
        printf("List Error: calling delete() on NULL List reference \n");
        exit(1);
    }
    
    if(L->length == 1)
    {
        clear(L);
    }else if(L->cursor == L->head)
    {
        L->cursor->next->prev = NULL;
        L->head = L->cursor->next;
        L->cursor->next = NULL;
        L->cursor->prev = NULL;
        L->length -= 1;
        L->index = -1;
    } else if(L->cursor == L->tail)
    {
        L->cursor->prev->next = NULL;
        L->tail = L->cursor->prev;
        L->cursor->next = NULL;
        L->cursor->prev = NULL;
        L->length -= 1;
        L->index = -1;
    } else
    {
        L->cursor->next->prev = L->cursor->prev;
        L->cursor->prev->next = L->cursor->next;
        L->cursor->next = NULL;
        L->cursor->prev = NULL;
        L->length -= 1;
        L->index = -1;
    }
    freeNode(&L->cursor);
}

void deleteFront(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling deleteFront() on NULL List reference \n");
        exit(1);
    }
    
    if(L->length == 1)
    {
        clear(L);
    }
    else if(L->cursor == L->head)
    {
        delete(L);
    }
    else
    {
        L->head = L->head->next;
        L->head->prev->next = NULL;
        L->head->prev = NULL;
        L->length -= 1;
        if(L->index != -1) {L->index -= 1;}
    }
}

void deleteBack(List L)
{
    if(L == NULL)
    {
        printf("List Error: calling deleteBack() on NULL List reference \n");
        exit(1);
    }
    
    if(L->length == 1)
    {
        clear(L);
    }
    else if(L->tail == L->cursor)
    {
        delete(L);
    }
    else
    {
        L->tail = L->tail->prev;
        L->tail->next->prev = NULL;
        L->tail->next = NULL;
        L->length -= 1;
    }
}

void clear(List L)
{
    L->head = NULL;
    L->tail = NULL;
    L->length = 0;
    L->cursor = NULL;
    L->index = -1;
    
}
