#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node* next;
};



void displayll(struct node *head);
void Push(struct node** headRef, int newData); 
void GetNthTest(void);
int GetNth(struct node* head, int number);
struct node* BuildOneTwoThree();

struct node *head = NULL; // declared globally

int main(){
 
  GetNthTest();
  
}

// displays the elements in the Linked list
void displayll(struct node* head){
  struct node *current;
  for(current =head;current != NULL; current = current->next)
    printf("%d",current->data);
  printf("\n");
}

// call the getnth function which returns the position of an element in the List
void GetNthTest(){

  struct node* myList = BuildOneTwoThree();
  printf("The created Linked list contains ");
  displayll(head);
  int position = GetNth(myList,2);
  printf("Index of %d in the list is: %d \n",2,position);
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

// returns the position(index) of a element of int type in the Linked List.
int GetNth(struct node* head,int num){

  struct node* current;
  int count=0;
  int k=0;
  for(current=head;current->next != NULL;current= current->next){ // traversing the Linked List.

    if(current->data != num)
      count++;
    
  }
  return(count);
}

