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
void enqueue(){
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
void dequeue(){
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
void display(){
	if(isEmpty()){
		printf("Queue is Empty\n");
	}
	else {
		printf("Elements present in the Queue ::");
		for(int i=front; i<rear; i++){
			printf("%d ",Queue[i]);
		}
	}
}

int main(){
	printf("1. Enter Element into Queue :: \n");
	printf("2. Deleting Element into Queue :: \n");
	printf("3. Display ::\n");
	printf("4. Exit ::\n");
	
	while(1){
		a:
		printf("\nEnter Your choice ::");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1 : enqueue();
					 break;
					 
			case 2 : dequeue();
					 break;
					 
			case 3 : display();
					 break;
					 
			case 4 : exit(0);
			
			default : printf("invalid choice ..\n");
			goto a;
							 
		}	
	}
}