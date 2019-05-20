#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *dir;
struct Node *esq;

};



struct Node* newNode(int data) 
{ 
  // Allocate memory for new node  
  struct Node* Node = (struct Node*)malloc(sizeof(struct Node)); 
  
  // Assign data to this node 
  Node->data = data; 
  
  // Initialize left and right children as NULL 
  Node->dir = NULL; 
  Node->esq = NULL; 
  return(Node); 
} 
 
int main() 
{ 
  /*create root*/
  struct node *root = newNode(1);   
  /* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
    
  
  root->esq = newNode(2); 
  root->dir = newNode(3); 
  /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->esq->esq = newNode(4); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
  
  getchar(); 
  return 0; 
}