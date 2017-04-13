//THIS PROGRAM SPLITS A LINKED LIST INTO TWO SUB LISTS

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

void displayll(struct node *head);
void append(struct node** a, struct node** b);
void PushE(struct node** head,int data);
struct node* newNode(void);
void createnodes(void);
void PushS(struct node** headRef, int data);
int length(struct node** headRef);
void moveNodes(struct node** list1Ref, struct node** list2Ref);




int main(){
  createnodes();
    
}

//create list source {1 3 5 3 56 89 89} and calls removeDuplicates function.

void createnodes(void){

  struct node* list1 = NULL,*list2 = NULL;
  PushE(&list1,1);
  PushE(&list1,2);
  PushE(&list1,3);
  PushE(&list2,1);
  PushE(&list2,2);
  PushE(&list2,3);
  
  printf("The source lists are:\n");
  displayll(list1);
  displayll(list2);
  moveNodes(&list1,&list2);
  printf("\n");
  displayll(list1);
  displayll(list2);
  
  
}

//move nodes from the head of second node and add to the head of first node
void moveNodes(struct node** list1Ref, struct node** list2Ref){

  struct node* current = *list2Ref;
  if(current != NULL){
    
   PushS(list1Ref,current->data); // push node to head of first node
  *list2Ref = current->next;
   free(current);
  
  }else{
    printf("no more node to move\n");
  }
}









//**********************************************************
//***************** HELPER FUNCTIONs ***********************
//**********************************************************

// used to find the length of the linked list
int length(struct node** headRef){

  struct node* current = *headRef;
  int len =0;
  while(current != NULL){
    len++;
    current= current->next;
  }
  return(len); // returns the length of the list
}


//displays the list 
void displayll(struct node* head){

  struct node* current = head;
  for(;current != NULL;current=current->next){

    printf("%d ",current->data);
  }
  printf("\n\n");
  
}

// This push function adds elememnts to the start of the linked list.
void PushS(struct node** headRef, int newData){

  struct node* current = *headRef,*nNode;
  nNode = newNode();
  nNode->data  = newData;
  nNode->next = *headRef;
  *headRef = nNode;
}


//Adds nodes to the end of the linked list
void PushE(struct node** headRef, int data){

  
  struct node* current = *headRef;
  struct node* nNode;
  nNode = newNode();
  nNode->data = data;
  nNode->next= NULL;

  if(current == NULL)
     *headRef = nNode;
  else{
    while(current->next != NULL)
      current = current->next;

    current->next = nNode;
    }
  
}

//creates new Node
struct node* newNode(void){

  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  if(newNode == NULL){
    printf("Cant allocate new Node\n");
    exit(0);
  }
  else{
    return(newNode);
  }
}
