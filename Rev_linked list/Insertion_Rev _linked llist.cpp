#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};
// Insertion ->
// case 1:
struct node* insertAtFirst(struct node *head,int val){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));

	ptr -> data = val;
	ptr -> prev = NULL;
	head -> prev = ptr;
	ptr -> next = head;
	head = ptr;
	
	return head;
}
// case 2:
struct node* insertAtEnd(struct node *head,int val){	
	
	struct node *p = head; 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> next = ptr;
	ptr -> prev = p;
	ptr -> next = NULL;
	
	return head;
}
//case 3:
struct node* insertAtIndex(struct node *head,int val,int index){	
	
	struct node *p=head;
	struct node *q=head->next;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	int i=0;
	
	while(i != index){
		p = p -> next;
		q = q -> next;
		i++;
	}
	ptr -> next = p -> next;
	ptr -> prev = p;
	q -> prev = ptr;
	p -> next = ptr; 
	return head;
	
}
// case 4 :
struct node* insert_At_User_Given_Val(struct node *head,int chg,int new_val){	
	
	struct node *p = head;
	struct node *q = head->next;
	 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = new_val;
	
	while(p -> data != chg && p -> next != NULL ){
		p = p -> next;
		q = q -> next;
	}
	if(p -> data == chg ){ 
		ptr -> next = p -> next;
		ptr -> prev = p;
		q -> prev = ptr;
		p -> next = ptr;
	}
	else{
		printf("\nwrong choice..\n");
	}
	return head;
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

	//linkedlistTraversal(head);
	//head=insertAtFirst(head,53);
	//head=insertAtEnd(head,76);
	//head=insertAtEnd(head,43);
	//head=insertAtIndex(head,70,0);
	//head=insert_At_User_Given_Val(head,10,22);
	
	Rev_Traversal(head);
}