
#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

int isEmpty(){
	if(rear == -1 && front == -1){
		return 1;
	}	
	return 0;
}

int isFull(){
	if(rear == N){
		return 1;
	}
	return 0;	
}

void enqueue(){
	
	if(isFull()) {
		printf("\nQueue is Overflow\n");	
	}
	else {
		printf("Enter elements :: ");
		int val;
		scanf("%d",&val);
		
		if(front == -1 && rear == -1){
			front = rear = 0;
			queue[rear++] = val;
		}
		else{
			queue[rear++] = val;
		}
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
		printf("Deleting element is %d",queue[front++]);
	}
}
void display(){
	if(isEmpty()){
		printf("\nQueue is Empty\n");
	}
	else{
		printf("elements present  in the Queue :: ");
		for(int i = front; i<rear; i++){
			printf("%d ",queue[i]);
		}
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