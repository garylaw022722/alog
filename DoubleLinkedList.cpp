#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


struct  Node {
    int data;
    Node * prev ;
    Node *next;
};
struct Node * head; 

void insert (int data){ 
    Node  *  newNode = (Node *) malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->prev =newNode->next = NULL;
    
    if(head==NULL){        
        head =newNode;
    }else{ 
        head->next = newNode;
        newNode->prev = head;
        head =newNode; // tail 
    }
    
}

void printNode(Node * node){

    if(node==NULL)return;
    printNode(node->prev);
    printf("%d  \n",node->data);
    
    
}

int main(){ 
    insert(10);
    insert(100);
    insert(110);
    insert(110);
    printNode(head);

    
    return 1; 
}