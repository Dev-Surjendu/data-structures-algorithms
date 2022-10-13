#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

int isEmpty(){
	if(front==NULL & rear==NULL)
		return 1;
	else
		return 0;
}

void enqueue(){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);
	ptr -> next = NULL;
	
	if(front==NULL & rear == NULL){
		front = rear = ptr;
	}	
	else{
		rear -> next = ptr;
		rear=ptr;
	}
}

void dequeue(){
	struct node* p=front;
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else if(front == rear){
		printf("\nDeleting %d element from the linked list",p->data);
		front=rear=NULL;
	}
	else{
		front = front -> next;
		printf("\nDeleting %d element from the linked list.\n",p->data);
		free(p);
	}
}

void display(){
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else{
		struct node* p=front;
		printf("\nElemnent present in the linked_list ::\n");
	
		while(p != rear){
			printf("\nElement :: %d",p->data);
			p=p->next;
		}
	}
	printf("\nElement :: %d",rear->data);
}

int main(){
	printf("1. Enter Element into Queue :: \n");
	printf("2. Deleting Element into Queue :: \n");
	printf("3. Display ::\n");
	printf("4. Exit ::\n");
	
	while(1){
		a:
		printf("\nEnter Your choice ::");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1 : enqueue();
					 break;
					 
			case 2 : dequeue();
					 break;
					 
			case 3 : display();
					 break;
					 	 
			case 4 : exit(0);
			
			default : printf("invalid choice ..\n");
			goto a;					 
		}	
	}
}