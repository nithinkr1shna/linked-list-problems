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
void createnodes(void);

int length(struct node** headRef);

void removeDuplicates(struct node** headRef);

int main(){
  createnodes();
    
}

//create list source {1 3 5 3 56 89 89} and calls removeDuplicates function.

void createnodes(void){

  struct node* source = NULL;
  PushE(&source,1);
  PushE(&source,3);
  PushE(&source,5);
  PushE(&source,5);
  PushE(&source,56);
  PushE(&source,89);
  PushE(&source,89);
  printf("The source list:");
  displayll(source);
  removeDuplicates(&source);
  printf("The modified lists:\n");
  displayll(source);
  
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


//remove duplicates from a given list
void removeDuplicates(struct node** headRef){

  struct node* current = *headRef,*previous;
  for(;current->next !=NULL;){
    
    if(current->data == current->next->data){ // checks if two adjacent nodes have same data
      struct node* next= current->next->next;  // create a new node assign its next field as second
      free(current->next);                     // nodes next field, put this value in first nodes next field.
      current->next = next;
      
    }else{

      current=current->next; //if not same, advance the list
    }
    
    
    printf("\n");
  }
  
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
