#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void linkedlistTraversal(struct node *head){
	
	struct node *p=head;	

	while(p ->next != head){
		printf("\nElement :: %d",p -> data);
		p = p -> next;
	}
	printf("\nElement :: %d\n",p -> data);	
}
// case 1:
struct node* InsertAtFirst(struct node* head,int val){
	struct node *p=head->next;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	
	while(p->next != head){
		p=p->next;
	}
	p->next=ptr;
	ptr->next=head;
	head=ptr;
	return head;
}
// case 2:
struct node* InsertAtIndex(struct node *head,int val,int index){	
	
	struct node *p=head;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	int i=0;
	
	while(i != index){
		p = p -> next;
		i++;
	}
	ptr -> next = p -> next;
	p -> next = ptr; 
	return head;
}
// case 3:
struct node* InsertAtEnd(struct node* head,int val){
	struct node *p=head->next;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	
	while(p->next != head){
		p=p->next;
	}
	p->next=ptr;
	ptr->next=head;
	return head;
} 
//case 4 :
struct node* InsertUserVal(struct node *head,int pre_val,int new_val){	
	
	struct node *p = head; 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = new_val;
	
	while(p -> data != pre_val && p -> next != head ){
		p = p -> next;
	}
	if(p -> data == pre_val ){ 
		ptr -> next = p -> next;
		p -> next = ptr;
	}
	else{
		printf("\nInvalid choice..\n");
	}
	return head;
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
	//head=InsertAtFirst(head,56);
	//head=InsertAtIndex(head,77,0);
	//head=InsertAtEnd(head,96);
	head=InsertUserVal(head,11,10);
	linkedlistTraversal(head);
	return 0;
}