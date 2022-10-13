#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* head=NULL;

void linkedlistTraversal(){
	struct node* p=head;
		while(p != NULL){
			printf("\nElement :: %d",p->data);
			p=p->next;
		}
}
int main(){
	
	printf("Creating 1st Node ---\n\n");
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);

	if(head == NULL){
		ptr->next=NULL;
		head=ptr;
	}
	linkedlistTraversal();
}