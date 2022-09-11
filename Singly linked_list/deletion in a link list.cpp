#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

 // case 1: Deleting the first element from the linked list
struct node* deleteAtFirst(struct node *head){
	struct node *p=head;
	head = head -> next;
	free(p);
	
	return head; 
}

// case 2 : Deletion at at the index position
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
	free(q);
	
	/* also u can write
	
	struct node *p=head;
	int i=0;
	
	while(i != index-1){
		p = p -> next;	
		i++;
	}
	struct node *q = p -> next;
	p -> next = q -> next;
	free(q);           */
	
	return head;
}

// case 3:
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

//case 4:
struct node* deleteAtUserval(struct node *head, int val){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> data != val && q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	if(q -> data == val){
		p -> next  = q -> next;
		free(q);
	}
	return head;
}
void linkedlistTraversal(struct node *head){
	
	while(head != NULL){
		printf("Elements :: ");
		printf("%d\n",head -> data);
		head = head -> next;
	}
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
	
	printf("Before Deletion :: \n");
	linkedlistTraversal(head);
	
	// head=deleteAtFirst(head); head=deleteAtFirst(head); // 2times deleting 
	// head=deleteAtIndex(head,2);
	// head=deleteAtEnd(head);
	// head=deleteAtUserval(head,9);
	
	printf("\nAfter Deletion :: \n");
	linkedlistTraversal(head);
		
	return 0;
}