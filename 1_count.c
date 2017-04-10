#include<stdio.h>

void countTest(void);
int count(struct node* head, int searchFor);
struct node{

  int data;
  struct node* next;
};

int main(){

  countTest();
  

}

void countTest(){

  List myList = BuildOneTwoThree();
  int count = Count(myList,2);
  printf("Count is \n",count);
}
