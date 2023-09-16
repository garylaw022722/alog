#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


struct  Node {
    int data;
    struct Node *next;
};
struct Node * head , *prev;

void push(int number){ 
    struct Node *  newNode = (struct Node *) malloc( sizeof(  struct Node *));
    
    newNode->data= number; 
    newNode->next =head;

    head = newNode; 
}

void   pop(){

    if (head== NULL) {
        printf("stack overflow in memory \n");
        return ;
    }
    Node * new_Head = head->next;
    int val  = head->data;
    free(head);
    head= new_Head;
    



   
}

void  printNodes(Node * s){
    if(s == NULL) return;
    printf("%d \n", s->data);
    printNodes(s->next);
    
}


int main(){ 
    push(10);
    push(20);
    push(50);

    pop();
    pop();
    printNodes(head);

    
    return 1; 
}