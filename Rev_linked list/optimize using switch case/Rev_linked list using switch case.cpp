#include <stdio.h>
#include <stdlib.h>

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

//case 2:
struct node* insertAtIndex(struct node *head,int val,int index){	
	struct node *p=head;
	struct node *q=head->next;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	int i=0;
	
	while(i != index & p->next != NULL){
		p = p -> next;
		q = q -> next;
		i++;
	}
	if(i == index){
		ptr -> next = p -> next;
		ptr -> prev = p;
		q -> prev = ptr;
		p -> next = ptr; 
	}
	else{
		printf("\nInvalid index position..\n");
	}
	return head;	
}

// case 3:
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

// case 4 :
struct node* insertUserVal(struct node *head,int chg,int new_val){	
	
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

// deletion ->

//case 5:
struct node* deleteAtFirst(struct node *head){
	struct node *p=head;
	head = head -> next;
	head -> prev = NULL;
	printf("\nDeleting %d element from the linked list.\n",p->data);
	free(p);
	
	return head; 
}

// case 6 :
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
	printf("\nDeleting %d element from the linked list.\n",q->data);
	free(q);
	
	return head;
}

// case 7 :
struct node* deleteAtEnd(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	p -> next = NULL;
	printf("\nDeleting %d element from the linked list.\n",q->data);
	free(q);
	
	return head;
}

// case 8:
struct node* deleteAtUserval(struct node *head, int val){
	struct node *p = head;
	struct node *q = head->next;
	struct node *n = q->next;
	
	while(q->data != val & q->next != NULL){
		p=p->next;
		q=q->next;
		n=n->next;
	}
	if(q->data == val){
		p->next=q->next;
		printf("\nDeleting %d element from the linked list.\n",q->data);
		n->prev=p;
		free(q);
	}
	return head;
}

//case 9:
void linkedlistTraversal(struct node *head){
	
	while(head != NULL){
		printf("Elements :: %d\n",head -> data);
		head = head -> next;
	}
}

//case 10:
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
	
	printf("\nBefore insertion or deletion :: \n");
	linkedlistTraversal(head);
	
	a:
	printf("\n1. Insert at the Beginning :: \n");
	printf("2. Insert at specific position :: \n");
	printf("3. Insert element at the End :: \n");
	printf("4. Insert after the Value ::\n");
	printf("5. Delete the first node :: \n");
	printf("6. Delete at specific position ::\n");
	printf("7. Delete the End node :: \n");
	printf("8. Delete the element with a given value ::\n");
	printf("\n9. Traverse/View list :: \n");
	printf("10. Reverse the list and display:: \n");
	printf("11. Exit ::\n");
	
	while(1){
		printf("\nEnter your choice :: ");
		int choice;
		scanf("%d",&choice);
		
		switch(choice){
			 
			case 1 : printf("Enter the value  :: ");
					 int num;
					 scanf("%d",&num);
					 head=insertAtFirst(head,num);
					 break;
					 
			case 2 : printf("Enter the Index_pos (Except last pos) :: ");
					 int ind;
					 scanf("%d",&ind);
					  
					 printf("Enter the value  :: ");
					 scanf("%d",&num);
					 head=insertAtIndex(head,num,ind);
					 break;
					 
			case 3 : printf("Enter the value  :: ");
					 scanf("%d",&num); 
					 head=insertAtEnd(head,num);
					 break;
					 
			case 4 : printf("Enter the value which is present in the linked list (Except last val):: ");
					 scanf("%d",&num);
	
				     printf("Enter the new value  :: ");
					 int new_val;
					 scanf("%d",&new_val);
					 head=insertUserVal(head,num,new_val);
					 break;
					 
			case 5 : head=deleteAtFirst(head);
					 break;
			
			case 6 : printf("Enter the index_position (Except first or last pos)::");
					 int index;
					 scanf("%d",&index);
					 head=deleteAtIndex(head,index);
					 break;
					 
			case 7 : head=deleteAtEnd(head);
					 break;
			
			case 8 : printf("Enter the value (Except first or last val)::");
					 int u_val;
					 scanf("%d",&u_val);
					 head=deleteAtUserval(head,u_val);
					 break;
			
			case 9 : printf("\nTraverse ::\n\n");
					 linkedlistTraversal(head);
					 break;
			
			case 10 : printf("\nReversed linked list  :: \n");
					 Rev_Traversal(head);
					 break;
					 
			case 11 : exit(0);
					 	
			default : printf("\n\tInvalid choice ...\n");
			goto a;
		}
	}
	return 0;
}