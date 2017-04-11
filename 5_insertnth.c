#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node* next;
};



void displayll(struct node *head);
void PushE(struct node** headRef, int newData);
void PushS(struct node** headRef, int newData);
void InsertNthTest(void);
void InsertNth(struct node** headRef, int index, int num);
int Length(struct node** head);
struct node* BuildOneTwoThree();

struct node *head = NULL; // declared globally

int main(){
  
  InsertNthTest();
  
}

// displays the elements in the Linked list
void displayll(struct node* head){
  if(Length(&head)==0)
    printf("empty\n");
  else{
    struct node *current;
    for(current =head;current != NULL; current = current->next)
      printf("%d",current->data);
    printf("\n");
  }
}

// call the InsertNth function which which adds an elemnt to the specified index position the List
void InsertNthTest(){

  struct node* myList =BuildOneTwoThree();
  printf("The created Linked list contains ");
  displayll(head);
  InsertNth(&head,4,6);
  printf("The modified linked List\n");
  displayll(head);
  
}

// function responsible for building the Linked List {123}
struct node* BuildOneTwoThree(){

  int i;
  for(i=1;i<4;i++)
    PushS(&head,i);
  return(head);
}

// This Push function adds elements of int type to the end of the List.

void PushE(struct node** headRef, int newData){
  struct node *newNode;
  struct node *current= *headRef;
  newNode = (struct node*)malloc(sizeof(struct node));
  if(newNode == NULL){ // checks wheather new node is allocated
    printf("cant allocate\n");
    exit(0);
  }
  newNode->data = newData;
  newNode->next = NULL;
  
  if(head == NULL){ // first ,checks if head is null
     head = newNode;
     
  }else{
    
     while(current->next != NULL)
       current = current->next;

     current->next = newNode; //creates link 
    
  }
}

// This push function adds elememnts to the start of the linked list.
void PushS(struct node** headRef, int newData){

  struct node* current = *headRef,*newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data  = newData;
  newNode->next = head;
  head = newNode;
}

// returns the length of the Linked List.
int Length(struct node** headRef){
  if(*headRef == NULL)
    return(0);
  struct node* current = *headRef;
  int len=0;
  for(;current->next != NULL ;current = current->next)
    len++;
  return(len);
}

void InsertNth(struct node** headRef, int index, int num){

  struct node* current = *headRef,*previous,*temp,*newNode;
  int len=Length(&current)+1,link_count=-1;
  
   if(len < index ){

    printf("Insertion not possible, index out of range\nExiting.....\n");
    exit(0);
    }
  printf("len %d index %d\n",len,index);
  
  if(len== index){
    PushE(&head,num);
  }else if(index ==0){
    PushS(&head,num);
    
    
  }else{

    for(;current->next;current= current->next){

      link_count++;
      printf("%d\t\n",link_count);
      if(link_count==index){
	break;
      }
      previous = current;
    }
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = current;
    previous->next = newNode;
    
  }
  
}
