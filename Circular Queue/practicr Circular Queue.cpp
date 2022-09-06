#include<stdio.h>
#include<stdlib.h>
#define n 5
int front=-1;
int rear=-1;
int Queue[n];

int isFull(){
	if((rear+1)%n == front)
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
		printf("\\nQueue is full\n");
	}
	else{
		printf("Enter the Elements ::");
		int val;
		scanf("%d",&val);
		
		if(front == -1 && rear == -1){
			front=rear=0;
			Queue[rear]=val;
		}
		else{
			rear = (rear+1)%n;
			Queue[rear]=val;
		}
	}
}
void dequeue(){
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else{
		if(front == rear){
			printf("Deleting elements %d\n",Queue[front]);
			front = rear = -1;
		}
		else{
			printf("Deleting elements %d\n",Queue[front]);
			front=(front+1)%n;
		}
	}
}
void display(){
	int i=front;
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else{
		while(i != rear){
		printf("%d ",Queue[i]);
		i=(i+1)%n;
	}
	printf("%d",Queue[rear]);
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