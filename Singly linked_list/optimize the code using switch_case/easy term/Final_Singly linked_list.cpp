#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* head=NULL;

// case 1: insert at the beginning
void insertAtFirst(){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);
	
	ptr -> next = head;
	head = ptr;
}

// case 2: insert at the index position
void insertAtIndex(){	
	struct node *p=head;
	
	printf("Enter the Index_pos :: ");
	int index;
	scanf("%d",&index);
				  
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Element :: ");
	scanf("%d",&ptr->data);
	
	int i=0;
	
	while(i != index){
		p = p -> next;
		i++;
	}
	ptr -> next = p -> next;
	p -> next = ptr; 
}

// case 3: insert at the End
void insertAtEnd(){	
	struct node *p = head; 	
	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);
	
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> next = ptr;
	ptr -> next = NULL;
}

//case 4: Insertion element at the next postion of user given value
void insertUserVal(){	
	struct node *p = head;
	
	printf("Enter the value which is present in the linked list :: ");
	int num;
	scanf("%d",&num);
					 	
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the new value  :: ");
	scanf("%d",&ptr->data); 	
	
	
	while(p -> data != num && p -> next != NULL ){
		p = p -> next;
	}
	if(p -> data == num ){  
		ptr -> next = p -> next;
		p -> next = ptr;
	}
	else{
		printf("\nInvalid choice..\n");
	}
}
// deletion::
 
// case 5: Deleting the first node from the linked list
void deleteAtFirst(){
	struct node *p=head;
	head = head -> next;
	printf("\nDeleting %d element from the linked list.\n",p->data);
	free(p); 
}

// case 6: Deletion  at the index position
void deleteAtIndex(){
	struct node *p=head;
	struct node *q=head->next;
	
	printf("Enter the index_position::");
	int index;
	scanf("%d",&index);
	
	if(index == 0 ){
		head = head -> next;
		printf("\nDeleting %d element from the linked list.\n",p->data);
		head=0;
	} 
	else{
		int i=0;
		while(i != index-1 & q->next != NULL){
			p = p -> next;
			q = q -> next;
			i++;
		}

		if(i == index-1){
			if(q->next == NULL){
				printf("\nDeleting %d element from the linked list.\n",q->data);
				p->next = NULL;
				free(q);
			}
			else{
				printf("\nDeleting %d element from the linked list.\n",q->data);
				free(q);
			}	
		}
	}
}

// case 7: deletionn at the end
void deleteAtEnd(){
	struct node *p=head;
	struct node *q=head->next;
	
	while(q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	p -> next = NULL;
	printf("\nDeleting %d element from the linked list.\n",q->data);
	free(q);
}

//case 8: delete the element with a given value 
void deleteAtUserval(){
	struct node *p=head;
	struct node *q=head->next;
	
	printf("Enter the value (Except first value)::");
	int val;
	scanf("%d",&val);
	
	
	while(q -> data != val && q -> next != NULL){
		p = p->next;
		q = q->next;
	}
	if(q -> data == val){
		p -> next  = q -> next;
		printf("\nDeleting %d element from the linked list.\n",q->data);
		free(q);
	}
}

// case 9: Traverse 
void linkedlistTraversal(){
	struct node* p=head;
	if(head == 0){
		printf("\nLinked list is Empty..\n");
	}
	else{
	printf("\nTraverse :: \n");
		while(p != NULL){
			printf("\nElement :: %d",p->data);
			p=p->next;
		}
	}
}
int main(){
	
	printf("Creating 1st Node ---\n\n");
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&ptr->data);

	if(head == NULL){
		ptr->next=NULL;
		head=ptr;
	}
	
	printf("\nBefore insertion or deletion ::");
	linkedlistTraversal();
	
	a:
	printf("\n\n1. Insert at the Beginning :: \n");
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
		int num;
		scanf("%d",&num);
		
		switch(num){
							 
			case 1 : insertAtFirst();
					 break;
					 
			case 2 : insertAtIndex();
					 break;
					 
			case 3 : insertAtEnd();
					 break;
					 
			case 4 : insertUserVal();
					 break;
					 
			case 5 : deleteAtFirst();
					 break;
			
			case 6 : deleteAtIndex();
					 break;
					 
			case 7 : deleteAtEnd();
					 break;
			
			case 8 : deleteAtUserval();
					 break;
					 
			case 9 : linkedlistTraversal();
					 break;
					 
			case 10 : exit(0);
					 	
			default : printf("\n\tInvalid choice ...\n");
			goto a;
		}
	}
}