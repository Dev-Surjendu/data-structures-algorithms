#include<stdio.h>
#include<stdlib.h>
#define n 5
int front=-1;
int rear =-1;
int Queue[n];

int isFull(){
	if(rear == n)
		return 1;
	else 
		return 0;
}
int isEmpty(){
	if(front == -1 && rear ==-1)
		return 1;
	else 
		return 0;		
}
void enqueue_rear(){
	if(isFull()){
		printf("Queue is full\n");
	}
	else{
		printf("Enter the value ::");
		int val;
		scanf("%d",&val);
		
		if(front == -1 && rear == -1){
			front=rear=0;
			Queue[rear++]=val;
		}
		else{
			Queue[rear++]=val;
		}
	}
}
void enqueue_front(){
	
	printf("Enter the value ::");
	int val;
	scanf("%d",&val);
		
	if(front == -1 && rear == -1){
			front=rear=0;
			Queue[front]=val;
			rear++;
	}
	else{
		if(front>0){
			Queue[--front]=val;
		}
		else{
			printf("Queue is full\n");
		}	
	}
}
void dequeue_front(){
	if(isEmpty()){
		printf("Queue is Empty\n");
	}
	else if(front == rear-1){
		printf("Deleting element %d",Queue[front]);
		front=rear=-1;
	}
	else {
		printf("\nDeleting element %d\n",Queue[front++]);
	}
}
void dequeue_rear(){
		if(isEmpty()){
		printf("Queue is Empty\n");
	}
	else if(rear == front+1){
		printf("\nDeleting element %d\n",Queue[--rear]);
		front=rear=-1;
	}
	else{
		printf("\nDeleting element %d\n",Queue[--rear]);
	}
}
void display(){
	if(isEmpty()){
		printf("Queue is Empty\n");
	}
	else {
		printf("Elements present in the Queue ::");
		if(rear>front){
			for(int i=front; i<rear; i++){
				printf("%d ",Queue[i]);
			}
		}
		else{
			for(int i=front; i<=rear; i++){
				printf("%d ",Queue[i]);
			}
		}
	}
}

int main(){
	printf("1. Insertion from Rear  :: \n");
	printf("2. Insertion from Front :: \n");
	printf("3. Deletion from Front  :: \n");
	printf("4. Deletion from Rear   :: \n");
	printf("5. Display ::\n");
	printf("6. Exit ::\n");
	
	while(1){
		a:
		printf("\nEnter Your choice ::");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1 : enqueue_rear();
					 break;
					 
			case 2 : enqueue_front();
					 break;
					 
			case 3 : dequeue_front();
					 break;
					 
			case 4 : dequeue_rear();
					 break;
			
			case 5 : display();
					 break;
					 
			case 6 : exit(0);
			
			default : printf("invalid choice ..\n");
			goto a;
							 
		}	
	}
}