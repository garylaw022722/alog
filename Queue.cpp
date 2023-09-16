#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


struct  Node {
    int data;
    struct Node *next;
};
struct Node * front , * rear;

void enqueue(int number){ 
    struct Node *  newNode = (struct Node *) malloc( sizeof(  struct Node *));
    
    newNode->data= number; 
    newNode->next = NULL;
    if(front == NULL  && rear ==NULL)
        front=rear= newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void  dequeue(){
    if(front == rear){
        printf( "the Queue is empty.......\n");
        front=rear=NULL;
        return;
    }

    Node * newFront = front->next;
    free(front);
    front = newFront;
}

void  printNodes(Node * s){
    if(s == NULL) return;
    printf("%d \n", s->data);
    printNodes(s->next);
    
}


int main(){ 
    enqueue(10);
    enqueue(40);
    enqueue(140);
    enqueue(240);
    enqueue(440);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printNodes(front);

    
    return 1; 
}