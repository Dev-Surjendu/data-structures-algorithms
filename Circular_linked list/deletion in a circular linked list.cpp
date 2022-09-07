#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
//case 1: 
struct node* deleteAtFirst(struct node *head){
	struct node *p=head->next;
	while(p ->next != head){
		p = p -> next;
	}
	struct node *q=p->next;
	head=head->next;
	p->next=head;
	free(q);
	
	return head; 
}
//case 2:
struct node* deleteAtIndex(struct node *head,int index){
	struct node *p=head;
	struct node *q=head->next;
	int i=0;
	
	while(i != index-1){
		p = p -> next;
		q = q -> next;
		i++;
	}
	p -> next = q -> next;
	printf("\n\nDeleting %d element from the Circular linked_list.\n",q->data);
	free(q);
	return head;
}
// case 3:
struct node* deleteAtEnd(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> next != head){
		p = p->next;
		q = q->next;
	}
	p -> next = head;
	free(q);
	return head;
}
// case 4:
struct node* deleteAtUserval(struct node *head, int val){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> data != val && q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	if(q -> data == val){
		p -> next  = q -> next;
		printf("\n\nDeleting %d element from the Circular linked_list.\n",q->data);
		free(q);
	}
	return head;
}
void linkedlistTraversal(struct node *head){
	
	struct node *p=head;	

	while(p ->next != head){
		printf("\nElement :: %d",p -> data);
		p = p -> next;
	}
	printf("\nElement :: %d",p -> data);	
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
	//head=deleteAtFirst(head);
	//head=deleteAtIndex(head,2);
	//head=deleteAtEnd(head);
	head=deleteAtUserval(head,3);
	printf("\nAfter deletion ::\n");
	linkedlistTraversal(head);
	return 0;
}