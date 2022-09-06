#include<stdio.h>
#include<stdlib.h>
#define n 5
int top=-1;
int stack[n];
void push(){
	if(top==n-1){
		printf("stack is overflow");
	}
	else{
		printf("Enter elements ::");
		int val;
		scanf("%d",&val);
		stack[++top]=val;
	}
}
void pop(){
	if(top == -1){
		printf("Stack is empty\n");
	}
	else{
		printf("pop element %d",stack[top--]);
	}
}
void display(){
	if(top == -1){
		printf("Stack is empty");
	}
	else{
		for(int i=top; i>=0; i--){
			printf("%d ",stack[i]);
		}
	}
}
int main(){
		a:
		printf("1. push ::\n");
		printf("2. pop ::\n");
		printf("3. display ::\n");
		printf("4. exit ::\n");
		
		while(1){
		printf("\nEnter your choice ::");
		int num;
		scanf("%d",&num);
		
		switch(num){
			case 1: push();
					break;
					
			case 2: pop();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			default: printf("invalid Choice ...\n");
			goto a;
		}
	}
}