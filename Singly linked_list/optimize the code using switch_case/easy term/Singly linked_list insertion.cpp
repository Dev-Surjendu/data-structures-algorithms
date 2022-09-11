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
// case 5: Traverse 
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
	printf("\n5. Traverse/View list :: \n");
	printf("6. Exit ::\n");
	
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
					 
			case 5 : linkedlistTraversal();
					 break;
					 
			case 6 : exit(0);
					 			 
			default : printf("\n\tInvalid choice ...\n");
			goto a;
		}
	}
}