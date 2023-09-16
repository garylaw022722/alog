#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data ;
    Node  * next; 
};
Node * head = NULL;

void deletePost(int index){
    Node * ptr = head; 
    if(index == 1){
        head = ptr->next;
        free(ptr);
        return;        
    }else{
        
        for(int i=0 ; i< index-2 ;i++){ 
            ptr = ptr->next;
        }
        Node * temp =  ptr->next->next; 
        ptr->next = temp;
        free(ptr->next);

    }

    





}

void  insertPost( int index ,int data){

    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data =data; 
    newNode->next = NULL;

    if(index == 1){
        newNode->next = head;
        head= newNode;      
    }else{
        Node * ptr  =  head;   
        for(int i = 0  ; i  < index-2  ; i++){
            ptr= ptr->next;    
        }

        newNode->next =  ptr->next; 
        ptr->next = newNode; 

    }
 

}

void printRecursive(Node * head){ 
    Node * ptr = head; 
    if (ptr  == NULL) return;
    
    printf("%d \n" ,ptr->data);
    printRecursive(ptr->next);
}

void reverseRecursive(Node * node ){
    
    if(node->next == NULL){
        head =node;
        return;
    }
    
    reverseRecursive(node->next);

    Node * pre  = node->next;
    pre->next = node;
    node->next = NULL;


}

void reverse(){
    Node * ptr  , *prev =NULL, *next ;
    ptr = head;
    while (ptr!= NULL)
    {
        // modify 1 0 4 2
        next = ptr->next;
        ptr->next = prev;        
        
        // backup 
        prev = ptr;
        // jump to next;
        ptr= next;
       
    }
    head =prev;
}

void printList(Node * nodeptr){
     
     while (nodeptr != NULL)
     {
        printf(" %d \n" ,nodeptr->data );
        nodeptr =  nodeptr->next;
     }
     
}
int main(){
    insertPost(1,10);
    insertPost(2,100);
    insertPost(3,4100);
    insertPost(3,6100);

    reverseRecursive(head);
    printList(head);
    while (1)
    {
        int index ; 
        int result  = scanf("%d", &index);
        if(result){
            deletePost(index); 
            printf("New List : \n");
            printList(head);
        }
        
    }
    
    
   
    return 0 ;
}