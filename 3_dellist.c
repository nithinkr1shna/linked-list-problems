#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node* next;
};



void displayll(struct node *head);
void Push(struct node** headRef, int newData); 
void DeleteListTest(void);
void DeleteList(struct node** head);
struct node* BuildOneTwoThree();

struct node *head = NULL; // declared globally

int main(){
 
  DeleteListTest();
  
}

// displays the elements in the Linked list
void displayll(struct node* head){
  struct node *current;
  for(current =head;current != NULL; current = current->next)
    printf("%d",current->data);
  printf("\n");
}

// call the getnth function which returns the position of an element in the List
void DeleteListTest(){

  struct node* myList = BuildOneTwoThree();
  printf("The created Linked list contains ");
  displayll(head);
  DeleteList(&myList);
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

void DeleteList(struct node** headRef){

  struct node *current= *headRef;
  struct node *temp;
  printf("Deleting......\n");
  for(;current != NULL;current = current->next){
    temp=current;
    free(temp); //frees each node as it traverses along the Linked List
    
  }
  printf("The Linked List is Deleted\n");
}
