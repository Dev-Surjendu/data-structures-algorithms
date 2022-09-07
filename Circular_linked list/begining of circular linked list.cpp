#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void linkedlistTraversal(struct node *head){
	
	struct node *p=head;	

	while(p ->next != head){
		printf("Element :: %d\n",p -> data);
		p = p -> next;
	}
	printf("Element :: %d",p -> data);	

	/*	Output will be same
	do{
		printf("Element : %d\n",p -> data);
		p = p -> next;
	}while(p ->next != head);*/

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
	
	head -> data = 7;
	head -> next = second;
	
	second -> data = 3;
	second -> next = third;
	
	third -> data = 9;
	third -> next = fourth;
	
	fourth -> data = 8;
	fourth -> next = head;
	
	linkedlistTraversal(head);
	
	return 0;
}