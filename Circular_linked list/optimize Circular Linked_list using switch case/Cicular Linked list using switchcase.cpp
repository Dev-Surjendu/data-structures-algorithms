#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

// insertion
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
	
	while(i != index & p -> next != head){
		p = p -> next;
		i++;
	}
	if(i == index){
		ptr -> next = p -> next;
		p -> next = ptr; 
	}
	else{
		printf("\nInvalid choice..\n");
	}
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

// deletion ::
//case 5: 
struct node* deleteAtFirst(struct node *head){
	struct node *p=head->next;
	while(p ->next != head){
		p = p -> next;
	}
	struct node *q=p->next;
	head=head->next;
	p->next=head;
	printf("\nDeleting %d element from the Circular linked_list.\n",q->data);
	free(q);
	
	return head; 
}

//case 6:
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
	printf("\nDeleting %d element from the Circular linked_list.\n",q->data);
	free(q);
	return head;
}

// case 7:
struct node* deleteAtEnd(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> next != head){
		p = p->next;
		q = q->next;
	}
	p -> next = head;
	printf("\nDeleting %d element from the Circular linked_list.\n",q->data);
	free(q);
	return head;
}

// case 8:
struct node* deleteAtUserval(struct node *head, int val){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> data != val && q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	if(q -> data == val){
		p -> next  = q -> next;
		printf("\nDeleting %d element from the Circular linked_list.\n",q->data);
		free(q);
	}
	return head;
}

// case 9:
void linkedlistTraversal(struct node *head){
	
	struct node *p=head;	

	while(p ->next != head){
		printf("\nElement :: %d",p -> data);
		p = p -> next;
	}
	printf("\nElement :: %d\n",p -> data);	
}
int main(){
	struct node *head;
	struct node *second; 
	struct node *third;
	
	// allocate memory for nodes in the linked list in heap
	head   = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third  = (struct node*)malloc(sizeof(struct node));
	
	printf("Create a Circular linked_list :: \n");
	
	int num1,num2,num3;
	printf("Enter three elements ::");
	scanf("%d %d %d",&num1,&num2,&num3);
	
	head -> data = num1;
	head -> next = second;
	
	second -> data = num2;
	second -> next = third;
	
	third -> data = num3;
	third -> next = head;
	
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
	printf("10. Exit ::\n");
	
	while(1){
		printf("\nEnter your choice :: ");
		int choice;
		scanf("%d",&choice);
		
		switch(choice){
			 
			case 1 : printf("Enter the value  :: ");
					 int num;
					 scanf("%d",&num);
					 head=InsertAtFirst(head,num);
					 break;
					 
			case 2 : printf("Enter the Index_pos :: ");
					 int ind;
					 scanf("%d",&ind);
					  
					 printf("Enter the value  :: ");
					 scanf("%d",&num);
					 head=InsertAtIndex(head,num,ind);
					 break;
					 
			case 3 : printf("Enter the value  :: ");
					 scanf("%d",&num); 
					 head=InsertAtEnd(head,num);
					 break;
					 
			case 4 : printf("Enter the value which is present in the linked list:: ");
					 scanf("%d",&num);
	
				     printf("Enter the new value  :: ");
					 int new_val;
					 scanf("%d",&new_val);
					 head=InsertUserVal(head,num,new_val);
					 break;
					 
			case 5 : head=deleteAtFirst(head);
					 break;
			
			case 6 : printf("Enter the index_position ::");
					 int index;
					 scanf("%d",&index);
					 head=deleteAtIndex(head,index);
					 break;
					 
			case 7 : head=deleteAtEnd(head);
					 break;
			
			case 8 : printf("Enter the value (Except last val)::");
					 int u_val;
					 scanf("%d",&u_val);
					 head=deleteAtUserval(head,u_val);
					 break;
			
			case 9 : printf("\nTraverse ::\n");
					 linkedlistTraversal(head);
					 break;
					 
			case 10 : exit(0);
					 	
			default : printf("\n\tInvalid choice ...\n");
			goto a;
		}
	}
	return 0;
}