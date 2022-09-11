#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

// case 1: insert at the beginning
struct node* insertAtFirst(struct node *head,int val){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));

	ptr -> data = val;
	ptr -> next = head;
	head = ptr;
	
	return head;
}

// case 2: insert at the index position
struct node* insertAtIndex(struct node *head,int val,int index){	
	
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

// case 3: insert at the End
struct node* insertAtEnd(struct node *head,int val){	
	
	struct node *p = head; 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> next = ptr;
	ptr -> next = NULL;
	
	return head;
}

//case 4 : Isertion element at the next postion of user given value
struct node* insertUserVal(struct node *head,int pre_val,int new_val){	
	
	struct node *p = head; 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = new_val;
	
	while(p -> data != pre_val && p -> next != NULL ){
		p = p -> next;
	}
	if(p -> data == pre_val ){ // here,if we did not given the if  statement then at the end position the insertion will be peformed 
		ptr -> next = p -> next;
		p -> next = ptr;
	}
	else{
		printf("\nInvalid choice..\n");
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
	
	printf("Before insertion :: \n");
	linkedlistTraversal(head);
	
	//head=insertAtFirst(head,53);
	//head=insertAtEnd(head,76);
	//head=insertAtIndex(head,70,2);
	head=insertUserVal(head,9,22);
	printf("\nAfter insertion :: \n");
	linkedlistTraversal(head);
	
	return 0;
}