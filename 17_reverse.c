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
struct node* sortedIntersect(struct node* a, struct node* b);
void reverse(struct node** headRef);
void reverse2(struct node** headRef);

int main(){
  createnodes();
    
}

//create list source.

void createnodes(void){

  struct node* a = NULL;
  PushE(&a,1);
  PushE(&a,3);
  PushE(&a,13);
  PushE(&a,13);
  PushE(&a,14);
  PushE(&a,68);
  PushE(&a,1);
  PushE(&a,2);
  PushE(&a,13);
  PushE(&a,7);
  PushE(&a,14);
  PushE(&a,45);
  printf("The source list\n");
  displayll(a);
  
  printf("The reverse list :\n");
  reverse(&a);
  displayll(a);
  
  
}


//reverse the list by creating a new list and pointing the headRef to the newly created list
void reverse(struct node** headRef){

  struct node* current= *headRef, *reverselist = NULL;
  
  for(;current != NULL; current = current->next){

    PushS(&reverselist,current->data);
    free(current); // frees the orginal list.

  }
  *headRef = reverselist;
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
