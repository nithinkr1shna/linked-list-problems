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
void createnodes_and_append(void);

//struct node *head = NULL;

int main(){
  createnodes_and_append();
  
  
}
//create list a {2 1 5} and b {11 56 89} and calls append function.

void createnodes_and_append(void){

  struct node* a = NULL;
  struct node* b = NULL;
  PushE(&a,2);
  PushE(&a,1);
  PushE(&a,5);
  printf("The first List:");
  displayll(a);
  PushE(&b,11);
  PushE(&b,56);
  PushE(&b,89);
  printf("The second list:");
  displayll(b);
  append(&a,&b);
  printf("\n");
  printf("The appended list:");
  displayll(a);
}

//appends two given list a & b : b to end of a
void append(struct node** aref, struct node** bref){

  struct node *list1 = *aref;
  
  if(*aref==NULL) //if a is empty
    *aref=*bref;
  else{
    
    for(;list1->next != NULL;list1 = list1->next)
      ;
    list1->next = *bref;
  }
  *bref=NULL;
}

void displayll(struct node* head){

  struct node* current = head;
  for(;current != NULL;current=current->next){

    printf("%d ",current->data);
  }
  printf("\n");
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
