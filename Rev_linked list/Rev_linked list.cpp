#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};
void Rev_Traversal(struct node *head){
	struct node *p=head;
	while(p -> next != NULL){
		p = p -> next;
	}
	while(p ->prev != NULL){
		printf("\nElements :: %d",p -> data);
		p = p -> prev;
	}
	printf("\nElements :: %d\n",p -> data);
}

int main(){

	struct node *head;
	struct node *second;
	struct node *third;
	
	head   = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third  = (struct node*)malloc(sizeof(struct node));
	printf("Create a linked list :: \n");
	
	int num1,num2,num3;
	printf("Enter three elements ::");
	scanf("%d %d %d",&num1,&num2,&num3);
	
	head -> data = num1;
	head -> prev = NULL;
	head -> next = second;

	second -> data = num2;
	second -> prev = head;
	second -> next = third;
	
	third -> data = num3;
	third -> prev = second;
	third -> next = NULL;

	Rev_Traversal(head);
}