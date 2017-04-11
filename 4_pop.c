//pop an element from the list {123}
//int a = pop(&head); =>1
//int b =pop(&head); =>2


#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node* next;
};



void displayll(struct node *head);
void Push(struct node** headRef, int newData); 
void PopTest(void);
int Pop(struct node** head);
int Length(struct node** head);
struct node* BuildOneTwoThree();

struct node *head = NULL; // declared globally

int main(){
  
  PopTest();
  
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

// call the pop function which returns the first of an element and removes it from the List
void PopTest(){

  struct node* myList =BuildOneTwoThree();
  printf("The created Linked list contains ");
  displayll(head);
  int a = Pop(&head);
  printf("\n%d is popped\n",a);
  printf("The modified Linked List is ");
  displayll(head);
  int b = Pop(&head);
  printf("%d is popped\n",b);
  printf("The modified Linked List is\n");
  displayll(head);
  int c = Pop(&head);
  displayll(head);
  
}

// function responsible for building the Linked List {123}
struct node* BuildOneTwoThree(){

  int i;
  for(i=1;i<4;i++)
    Push(&head,i);
  return(head);
}

// This Push function adds elements of int type to the end of the List.

void Push(struct node** headRef, int newData){
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

// pops each element from the head of the Linked List.
int Pop(struct node** headRef){

  struct node* current = *headRef;
  struct node* previous;
  int length = Length(&current); // get the length of the linked list.
  int value;
  if(length == 0){ // an empty linked list

    printf("Error: nothing to pop\nExiting......\n");
    exit(0);
  }else{ // contains some element.
     int count=0;
     for(;current->next;current = current->next){
       count++;
       if(count ==2){
         break;
       }
       previous= current;
     }
     head = current;
     value = previous->data;
     return(value);
     
   }
  
  
}

//returns the length of the Linked List.
int Length(struct node** headRef){
  if(*headRef == NULL)
    return(0);
  struct node* current = *headRef;
  int len=0;
  for(;current->next != NULL ;current = current->next)
    len++;
  return(len);
}
