//THIS PROGRAM SPLITS A LINKED LIST INTO TWO SUB LISTS

//If the number of elements is even the sublists contain equal number
//of elements else the second sublist contain one plus the first sublist.


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
void createnodes_and_split(void);
void frontbacksplit(struct node** sourceRef, struct node** frontRef, struct node** backRef);
int length(struct node** headRef);


int main(){
  createnodes_and_split();
    
}

//create list source {2 1 5 11 56 89} and calls frontbacksplit function.

void createnodes_and_split(void){

  struct node* source = NULL;
  struct node* front = NULL, *back = NULL ;
  PushE(&source,2);
  PushE(&source,1);
  PushE(&source,5);
  PushE(&source,11);
  PushE(&source,56);
  PushE(&source,89);
  //PushE(&source,99);
  printf("The source list:");
  displayll(source);
  frontbacksplit(&source,&front,&back);
  printf("The split lists:\n");
  displayll(front);
  displayll(back);
}

//This function splits the source list into two sublist
void frontbacksplit(struct node** sourceRef, struct node** frontRef, struct node** backRef){

  struct node* source = *sourceRef;
  int source_len = length(&source),counter=1;
    for(;source !=NULL;source= source->next){

      if(counter <= (source_len/2)){ // if the list has equal or less elements thn half the length of the source list
        PushE(frontRef,source->data); 
      }else{
	PushE(backRef,source->data);
      }
      counter++;
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
