#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head=NULL;
// case 1:
void insertAtFirst(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&temp->data);

	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
		
	head=temp;
}
//case 2:
void insertAtIndex(){	
	struct node *p=head;
	struct node *q=head->next;
	
	printf("Enter the Index_pos :: ");
	int index;
	scanf("%d",&index);
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));			  
	printf("Enter the Element :: ");
	scanf("%d",&temp->data);
	
	int i=0;
	
	while(i != index & p->next != NULL){
		p = p -> next;
		q = q -> next;
		i++;
	}
	if(i == index){
		if(p->next == NULL){
			p->next=temp;
			temp->next=NULL;
			temp->prev=p;
		}
		else{
			temp -> prev = p;
			p -> next = temp; 
			temp -> next = p -> next;
			q -> prev = temp;
		}
	}
	else{
		printf("\nInvalid index position..\n");
	}	
}
//case 3:
void insertAtEnd(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&temp->data);
	
	struct node* p=head;
	while(p->next != NULL){
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
	temp->next=NULL;
}
//case 4
void insertUserVal(){	
	
	struct node *p = head;
	struct node *q = head->next;
	
	printf("Enter the value which is present in the linked list :: ");
	int num;
	scanf("%d",&num);
					 	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the new value  :: ");
	scanf("%d",&temp->data);
	
	while(p -> data != num && p -> next != NULL ){
		p = p -> next;
		q = q -> next;
	}
	if(p -> data == num ){
		if(p->next == NULL){
			p->next=temp;
			temp->next=NULL;
			temp->prev=p;
		}
		else{
		temp -> next = p -> next;
		temp -> prev = p;
		q -> prev = temp;
		p -> next = temp;
		}
	}
	
	else{
		printf("\nwrong choice..\n");
	}
}
// case 5:

void deleteAtFirst(){
	
	if(head==0){
		printf("\nLinked list is Empty..\n");
	}
	else if(head->next==NULL & head->prev == NULL){
		printf("\nDeleting %d element from the linked list.\n",head->data);
		head=0;
	}
	else{
		struct node *p=head;
		head = head -> next;
		head -> prev = NULL;
		printf("\nDeleting %d element from the linked list.\n",p->data);
		free(p);
	}
}
// case 6:
void deleteAtIndex(){
	struct node *p=head;
	
	printf("Enter the index_position (Except last pos)::");
	int index;
	scanf("%d",&index);
	
	if(index == 0 ){
		head = head -> next;
		head -> prev = NULL;
		printf("\nDeleting %d element from the linked list.\n",p->data);
		free(p);
	} 
	else{
		int i=0;
		while(i != index-1){
			p = p -> next;
			i++;
		}
		if(i == index-1){
			if(p->next==NULL & p->prev==NULL){
				printf("%d",p->data);
				printf("\nDeleting %d element from the linked list.\n",p->data);
				head=0;
			}
		else{			
			struct node *q = p->next;
			struct node *n = q->next;
			p -> next = n;
			n -> prev = p;

			printf("\nDeleting %d element from the linked list.\n",q->data);
			free(q);
			}
		}
	}
}
//case 7 :
void deleteAtEnd(){
	
	if(head==0){
		printf("\nLinked list is Empty..\n");
	}
	else if(head->next==NULL & head->prev == NULL){
		printf("\nDeleting %d element from the linked list.\n",head->data);
		head=0;
	}
	else{
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
}

//case 8:
void deleteAtUserval(){

	struct node *p = head;
	struct node *q = head->next;
	struct node *n = q->next;
	
	printf("Enter the value (Except first value)::");
	int val;
	scanf("%d",&val);
	
	if(q->next==NULL){
		p->next=NULL;
		printf("\nDeleting %d element from the linked list.\n",q->data);
		free(q);
	}
	else{	
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
	}
	
}					 
//case 9:
void linkedlistTraversal(){
	if(head==0){
		printf("\nLinked list is Empty..\n");
	}
	else{
		printf("\nTraverse :: \n");
		
		struct node* p=head;
		while(p != NULL){
			printf("\nElement :: %d",p->data);
			p=p->next;
		}
	}
}

// case 10:
void Rev_Traversal(){
	struct node *p=head;
	while(p -> next != NULL){
		p = p -> next;
	}
	printf("\nReversed linked list  :: \n");
	while(p ->prev != NULL){
		printf("\nElements :: %d",p -> data);
		p = p -> prev;
	}
	printf("\nElements :: %d\n",p -> data);
}

int main(){
	
	printf("Creating 1st Node ---\n\n");
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element :: ");
	scanf("%d",&temp->data);

	if(head == NULL){
		temp->prev=NULL;
		temp->next=NULL;
		head=temp;
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
	printf("10. Reverse the list and display:: \n");
	printf("11. Exit ::\n");
	
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
					 
		    case 10: Rev_Traversal();
					 break;
					  
			case 11 : exit(0);
					 	
			default : printf("\n\tInvalid choice ...\n");
			goto a;
		}
	}
}