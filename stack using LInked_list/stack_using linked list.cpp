#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;

int isEmpty(){
	if(top == NULL)
		return 1;
	else 
		return 0;
}
void push(){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);
	
	ptr -> next = top;
	top = ptr;
}
void pop(){
	if(isEmpty()){
		printf("\nstack is empty\n");
	}
	else{
		struct node *p=top;
		top = top -> next;
		printf("\nDeleting %d element from the linked list.\n",p->data);
		free(p);
	} 
}
void display(){
	
	if(isEmpty()){
		printf("\nstack is empty\n");
	}
	else{
		struct node* p=top;
		printf("\nElemnent present in the linked_list ::\n");
		while(p != NULL){
			printf("\nElement :: %d",p->data);
			p=p->next;
		}
	}
}

int main(){
	printf("Creating 1st Node ---\n\n");
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);
	printf("\nFirst node -> %d\n\n",ptr->data);
	

	if(top == NULL){
		ptr->next=NULL;
		top=ptr;
	}
	a:
		printf("1. push ::\n");
		printf("2. pop ::\n");
		printf("3. display ::\n");
		printf("4. exit ::\n");
		
		while(1){
		printf("\n\nEnter your choice ::");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1: push();
					break;
					
			case 2: pop();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			default: printf("invalid Choice ...\n");
			goto a;
		}
	}
}
