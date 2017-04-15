//THIS PROGRAM merges two linked list in alternating order

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

void displayll(struct node *head);
void PushE(struct node** head,int data);
struct node* newNode(void);
void createnodes(void);
void PushS(struct node** headRef, int data);
int length(struct node** headRef);
void moveNodes(struct node** list1Ref, struct node** list2Ref);
void shuffleMerge(struct node** aRef, struct node** bRef );
void alternatingSplit(struct node** sourceRef, struct node** aRef, struct node** bRef );
struct node* sortedMerge(struct node* a, struct node* b);
void frontbacksplit(struct node** sourceRef, struct node** frontRef, struct node** backRef);
void mergeSort(struct node** list);

int main(){
  createnodes();
    
}

//create list source.

void createnodes(void){

  struct node* source1 = NULL;
  PushE(&source1,1);
  PushE(&source1,36);
  PushE(&source1,98);
  PushE(&source1,3);
  PushE(&source1,13);
  PushE(&source1,14);
  displayll(source1);
  
  
  printf("The modified lists is:\n");
  mergeSort(&source1);
  displayll(source1);
  
  
}

void mergeSort(struct node** headRef){

  struct node* head =*headRef,*a=NULL,*b=NULL,*result;
  if(head == NULL || head->next == NULL)
    return;
  
  frontbacksplit(&head,&a,&b);
  displayll(a);
  displayll(b);
  mergeSort(&a);
  mergeSort(&b);
  *headRef = sortedMerge(a,b);
  




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


  void frontbacksplit(struct node** sourceRef, struct node** frontRef, struct node** backRef){

  struct node* source = *sourceRef;
  int source_len = length(&source),counter=1;
    for(;source !=NULL;source= source->next){

      if(counter <= (source_len/2)){ // if the list has equal or less elements thn half the length of the source list
        PushE(frontRef,source->data); // alternative  
      }else{
	PushE(backRef,source->data);
      }
      counter++;
    }    
  
  
  
}
  
//sorted merge using recursion
struct node* sortedMerge(struct node* a, struct node* b){

  struct node* s1 = a,*s2 =b,*result = NULL;
  if(s2 == NULL) //if second list is empty return first list
    return(s1);
  else if(s1 == NULL) // if first list is empty return second list
    return(s2);

  if(a->data <= b->data){ //checks if a's node lt or eq to b's node
    result =a;
    result->next = sortedMerge(a->next,b); // recursive call to the function.
  }else{

    result=b;
    result->next = sortedMerge(a,b->next);
  }
  
  return(result);
    
}

//shuffle merge , merges to list to one in alternating order
void shuffleMerge(struct node** aRef, struct node** bRef){

  struct node* s1 = *aRef, *s2 = *bRef;
  
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
