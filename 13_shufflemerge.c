//THIS PROGRAM merges two linked list in alternating order

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
void shuffleMerge(struct node** aRef, struct node** bRef );
void alternatingSplit(struct node** sourceRef, struct node** aRef, struct node** bRef );


int main(){
  createnodes();
    
}

//create list source.

void createnodes(void){

  struct node* source1 = NULL,*source2 = NULL;
  PushE(&source1,1);
  PushE(&source1,2);
  PushE(&source1,3);
  PushE(&source2,7);
  PushE(&source2,13);
  PushE(&source2,1);
  displayll(source1);
  displayll(source2);
  shuffleMerge(&source1,&source2);
  printf("The modified lists is:\n");
  displayll(source2);
  
  
}

//shuffle merge , merges to list to one in alternating order
void shuffleMerge(struct node** aRef, struct node** bRef){

  struct node* s1 = *aRef, *s2 = *bRef,*temp=NULL;
  int count=1;
  
  if(s2 == NULL){
    displayll(s1);
  }
  for(;s2 != NULL; s2 = s2->next){
    if(s1 ==NULL)
      break;
    moveNodes(&s2->next,&s1);
    
    s2=s2->next;
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

//alternating split.
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
