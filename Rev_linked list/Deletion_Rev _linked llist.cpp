#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void linkedlistTraversal(struct node *head){
	
	while(head != NULL){
		printf("Elements :: %d\n",head -> data);
		head = head -> next;
	}
}

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
// deletion ->
//case 1:
struct node* deleteAtFirst(struct node *head){
	struct node *p=head;
	head = head -> next;
	head -> prev = NULL;
	free(p);
	
	return head; 
}
// case 2 :
struct node* deleteAtEnd(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	p -> next = NULL;
	free(q);
	return head;
}

// case 3 :
struct node* deleteAtIndex(struct node *head,int index){
	struct node *p=head;
	int i=0;
	
	while(i != index-1){
		p = p -> next;
		i++;
	}
	struct node *q = p->next;
	struct node *n = q->next;
	p -> next = n;
	n -> prev = p;
	free(q);
	return head;
}
// case 4;
struct node* delete_At_User_Given_Val(struct node *head, int val){
	struct node *p = head;
	struct node *q = head->next;
	struct node *n = q->next;
	
	while(q->data != val & q->next != NULL){
		p=p->next;
		q=q->next;
		n=n->next;
	}
	if(q->data == val){
		p->next=n;
		n->prev=p;
		free(q);
	}
	return head;
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
	
	//head=deleteAtFirst(head);
	//head=deleteAtEnd(head);
	//head=deleteAtIndex(head,1); // if statement
	//head=delete_At_User_Given_Val(head,10);
	linkedlistTraversal(head);
	
	printf("\nAfter reverse ::\n");
	Rev_Traversal(head);
}