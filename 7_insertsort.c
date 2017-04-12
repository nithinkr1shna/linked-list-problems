#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node* next;
};


void print(int num);
void displayll(struct node *head);
void PushE(struct node** headRef, int newData);
void PushS(struct node** headRef, int newData);
void InsertSortTest(void);
void InsertSort(struct node** headRef);
void InsertNth(struct node** headRef, int index, int num);
int Length(struct node** head);
int last(struct node** headRef);
void builddefaultList(struct node** headRef);
void PushD(struct node** headRef, int data);

struct node *head = NULL; // declared globally
struct node *to_sort = NULL;
int main(){
  
  InsertSortTest();
  
}
void builddefaultList(struct node** headRef){
  
  PushD(&to_sort,4);
  PushD(&to_sort,2);
  PushD(&to_sort,1);
  PushD(&to_sort,3);
  PushD(&to_sort,6);
}

void PushD(struct node** headRef, int newData){

  struct node* current = *headRef,*newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data  = newData;
  newNode->next = to_sort;
  to_sort = newNode;
}

// displays the elements in the Linked list
void displayll(struct node* start){
  
  struct node *current;
    for(current =start;current != NULL; current = current->next)
      printf("%d ",current->data);
    printf("\n");
     
}


// call the InsertSort function which takes elements from to_sort list to head list .
void InsertSortTest(){

  printf("\nThe created Linked list contains ");
  builddefaultList(&to_sort);
  displayll(to_sort);
  InsertSort(&to_sort);
  displayll(head);
 
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
  
  if(len < index ){ //if index greater than length of linked list plus one

    printf("Insertion not possible, index out of range\nExiting.....\n");
    exit(0);
    }
  
  if(len== index){ // if length of linked list is equal to index , then add the element to end of the list using PushE
    PushE(&head,num);
  }else if(index ==0){ // if index is 0 element is added to the head position using PushS function.
    PushS(&head,num);
    
    
  }else{ // adds node to the intermediate positions

    for(;current->next;current= current->next){

      link_count++;
      
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

// Adds elements to the sorted Linked List in increasing order

void SortedInsert(struct node** headRef, int num){

  struct node* current = *headRef,*previous,*newNode;
  int len = Length(&current)+1,count=0;
 
  for(;current->next;current=current->next,count++){
    if(current== NULL)
      PushS(&head,num);
    
    if(num < current->data && count==0){ // insert node if the num is less than the first node
	PushS(&head,num);
	break;

    }
      if(num < current->data){ // insert in between
      newNode= (struct node*)malloc(sizeof(struct node));
      newNode->data = num;
      newNode->next = previous->next;
      previous->next = newNode;
      break;
    }
    
    if(num >last(&head)){ // num is greater than the last element then add the number to the end of the list.
      PushE(&head,num);
      break;
    }
    if(num > current->data && len==(count+2)  ){ // add element to second last position.
      InsertNth(&head,len-1,num);
      break;
       
      }
    
    previous=current;     
   
  }
  
  printf("\n");
}

// this functio is an auxilliary function used by sortedinsert fn
// returns the last node data in the linked list.
int last(struct node** headRef){

  struct node* current = *headRef;
  while(current->next !=NULL){
    current= current->next;
  }
  return(current->data);
}


void InsertSort(struct node** headRef){
  
  struct node* current = *headRef,*previous;
  printf("The LIst should be minimum 2 in len\n");
  PushS(&head,current->data);  //pushes the first data what ever it is
     previous = current;
     current= current->next;
     if(current->data > previous->data){
       PushE(&head,current->data); // if the second data is greater then it is added to the end
     }else{

       PushS(&head,current->data); // if the second data is less then it id added to the head  
     }
     current = current->next;
     for(;current->next;current= current->next){ // calls SortedInsert can only be called on list having min 2 elements.
    SortedInsert(&head,current->data);
    }
  SortedInsert(&head,current->data); // pushes the last element
  
}
