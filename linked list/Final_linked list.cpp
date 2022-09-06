#include <stdio.h>
#include <stdlib.h>

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

//case 4 : Insertion element at the next postion of user given value
struct node* insertUserVal(struct node *head,int chg,int new_val){	
	
	struct node *p = head; 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = new_val;
	
	while(p -> data != chg && p -> next != NULL ){
		p = p -> next;
	}
	if(p -> data == chg ){ // here,if we did not given the if  statement then at the end position the insertion will be peformed 
		ptr -> next = p -> next;
		p -> next = ptr;
	}
	else{
		printf("\nwrong choice..\n");
	}
	return head;
}

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
	
	// For Insertion ::
	/*int num;
	printf("Before insertion :: \n");
	linkedlistTraversal(head);*/
	
	// case 1:
	/*printf("Enter element at the Beginning :: ");
	scanf("%d",&num);
	head=insertAtFirst(head,num);*/
	
	//case 2: 
	/*printf(" Enter the index position where you want to insert the value :: ");
	int ind;
	scanf("%d",&ind);
	
	printf("Enter the value  :: ");
	scanf("%d",&num);
	head=insertAtIndex(head,num,ind);*/
	
	//case 3 :
	/*printf("Enter element at the End :: ");
	scanf("%d",&num);
	head=insertAtEnd(head,num);*/
	
	// case 4 :
	/*printf("Enter the value which is present in the linked list :: ");
	scanf("%d",&num);
	
	printf("Enter the new value  :: ");
	int new_val;
	scanf("%d",&new_val);
	head=insertUserVal(head,num,new_val);
	
	printf("\nAfter insertion :: \n");
	linkedlistTraversal(head);*/
	
	// For Deletion ::
	int n;
	printf("Before Deletion :: \n");
	linkedlistTraversal(head);
	
	// head=deleteAtFirst(head); head=deleteAtFirst(head);
	// head=deleteAtIndex(head,2);
	// head=deleteAtEnd(head);
	
	// printf("\nAfter Deletion :: \n");
	//head=deleteAtUserval(head,9);
	
	//printf("\nAfter Deletion :: \n");
	//linkedlistTraversal(head);
		
	return 0;
}