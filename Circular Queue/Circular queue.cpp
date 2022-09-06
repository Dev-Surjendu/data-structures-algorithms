#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

int isEmpty(){
	if(rear == -1 && front == -1){
		return 1;
	}else{	
		return 0;
	}
}

int isFull(){
	if(((rear+1)%N) == front){
		return 1;
	}
	return 0;	
}

void enqueue(){
	int val;
	if(isFull()) {
		printf("\nQueue is Overflow\n");
		}		

	else if	(front == -1 && rear == -1){
			
		printf("Enter elements :: ");
		scanf("%d",&val);
			front = rear = 0;
			queue[rear] = val;
	}
	
	else{
		printf("Enter elements :: ");
		scanf("%d",&val);
		
		rear=(rear+1)%N ;
		queue[rear] = val;
	}
}
void dequeue() {
	if(isEmpty()) {
		printf("\nQueue is Empty\n");
	}
	else if(front == rear) { 
		printf("Deleting element is %d",queue[front]);
		front = rear = -1;
	}
	else {
		printf("Deleting element is %d",queue[front]);
		front=(front+1)%N;
	}
}
void display(){
	int i=front;
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else{
		printf("Elements present  in the Queue :: ");
		while(i != rear){
			printf("%d ",queue[i]);
			i=(i+1)%N;
		}
		printf("%d",queue[rear]);
	}
}
int main(){
	
	a:
	printf("1. Enter elements into Queue :\n");
	printf("2. Delete elements from Queue :\n");
	printf("3. Display :\n");
	printf("4. Exit :\n");
	
	while(1){
	
	printf("\nEnter your choice :: ");
	int num;
	scanf("%d",&num);
		
		switch(num){
			case 1: enqueue(); 
					break;
					
			case 2:	dequeue();	
					break;
			
			case 3: display(); 
				    break;
			
			case 4: exit(0);
					  
			default:
					printf("Invalid choice..\n\n"); 	
					goto a;
		}
	}
	
}