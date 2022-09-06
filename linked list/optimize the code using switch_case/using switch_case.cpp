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
	printf("\nDeleting %d element from the linked list.\n",p->data);
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
	printf("\nDeleting %d element from the linked list.\n",q->data);
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
	printf("\nDeleting %d element from the linked list.\n",q->data);
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
		printf("\nDeleting %d element from the linked list.\n",q->data);
		free(q);
	}
	return head;
}
void linkedlistTraversal(struct node *head){
	
	while(head != NULL){
		printf("Elements :: %d\n",head -> data);
		head = head -> next;
	}
}

int main(){
	struct node *head;
	struct node *second; 
	
	// allocate memory for nodes in the linked list in heap
	head   = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	
	// 1st we create two nodes ::
	printf("Create a linked list :: \n");
	
	int num1,num2;
	printf("Enter two elements ::");
	scanf("%d %d",&num1,&num2);
	
	// link fist and second node
	head -> data = num1;
	head -> next = second;

	// Terminate the list at the second node
	second -> data = num2;
	second -> next = NULL;
	
	printf("\nBefore insertion or deletion :: \n");
	linkedlistTraversal(head);
	
	printf("\n1. Traversal :: \n");
	printf("2. Insert at the Beginning :: \n");
	printf("3. Insert at specific position :: \n");
	printf("4. Insert element at the End :: \n");
	printf("5. Insert after the Value ::\n\n");
	printf("6. Delete the first node :: \n");
	printf("7. Delete at specific position ::\n");
	printf("8. Delete the End node :: \n");
	printf("9. Delete the element with a given value ::\n");
	printf("10. Exit ::");
	
	while(1){
		printf("\nEnter your choice :: ");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1 : printf("\nAfter :: \n");
					 linkedlistTraversal(head);
					 break;
					 
			case 2 : printf("Enter the value  :: ");
					 scanf("%d",&num);
					 head=insertAtFirst(head,num);
					 break;
					 
			case 3 : printf("Enter the Index_pos :: ");
					 int ind;
					 scanf("%d",&ind);
					  
					 printf("Enter the value  :: ");
					 scanf("%d",&num);
					 head=insertAtIndex(head,num,ind);
					 break;
					 
			case 4 : printf("Enter the value  :: ");
					 scanf("%d",&num); 
					 head=insertAtEnd(head,num);
					 break;
					 
			case 5 : printf("Enter the value which is present in the linked list :: ");
					 scanf("%d",&num);
	
				     printf("Enter the new value  :: ");
					 int new_val;
					 scanf("%d",&new_val);
					 head=insertUserVal(head,num,new_val);
					 break;
					 
			case 6 : head=deleteAtFirst(head);
					 break;
			
			case 7 : printf("Enter the index_position ::");
					 int index;
					 scanf("%d",&index);
					 head=deleteAtIndex(head,index);
					 break;
					 
			case 8 : head=deleteAtEnd(head);
					 break;
			
			case 9 : printf("Enter the value ::");
					 int u_val;
					 scanf("%d",&u_val);
					 head=deleteAtUserval(head,u_val);
					 break;
					 
			case 10 : exit(0);
					 	
			default : printf("Invalid choice ...");
		}
	}
    return 0;
}