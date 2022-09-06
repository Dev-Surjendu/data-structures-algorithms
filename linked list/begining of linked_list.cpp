#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void linkedlistTraversal(struct node *head){
	
	while(head != NULL){
		printf("Elements :: ");
		printf("%d\n",head -> data);
		head = head -> next;
	}
	
	/*	Output will be same
	while(ptr ->next != NULL){
		printf("%d\n",head -> data);
		head = head -> next;
	}
	printf("%d",head -> data);*/	
}

int main(){
	struct node *head;
	struct node *second; 
	struct node *third;
	struct node *fourth;
	
	// allocate memory for nodes in the linked list in heap
	head   = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third  = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));	
	
	// link fist and second node
	head -> data = 7;
	head -> next = second;
	
	// link second and third node
	second -> data = 3;
	second -> next = third;
	
	// link third and fourth node
	third -> data = 9;
	third -> next = fourth;
	
	// Terminate the list at the forth node
	fourth -> data = 8;
	fourth -> next = NULL;
	
	linkedlistTraversal(head);
	
	return 0;
}