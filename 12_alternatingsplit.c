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
void alternatingSplit(struct node** sourceRef, struct node** aRef, struct node** bRef );



int main(){
  createnodes();
    
}

//create list source {1 2 3 4 5 6} and calls removeDuplicates function.

void createnodes(void){

  struct node* source = NULL,*a = NULL,*b=NULL;
  PushE(&source,1);
  PushE(&source,2);
  PushE(&source,3);
  PushE(&source,4);
  PushE(&source,5);
  PushE(&source,6); 
  
  printf("The source lists is:\n");
  displayll(source);
  alternatingSplit(&source, &a, &b);
  printf("The alternatingSplit sublists:\n");
  displayll(a);
  displayll(b);
  
}

void alternatingSplit(struct node** sourceRef, struct node** aRef, struct node** bRef){

  struct node* current = *sourceRef,*temp=NULL,*nNode,*previous;
  int count=1;
  for(;current != NULL; current= current->next){
    
    count++;
    nNode=newNode();
    PushS(&temp,current->data);
    
    if(count %2 != 0){
      
      moveNodes(aRef,&temp);
      
    }else{
      
      moveNodes(bRef,&temp);
      
    }
  }
}









//**********************************************************
//***************** HELPER FUNCTIONs ***********************
//**********************************************************

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
