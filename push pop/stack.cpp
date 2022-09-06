#include<stdio.h>
#include<stdlib.h>
int top = -1;
int stack[5];

void push(){
	int val;
	
	if(top == 5-1){
		printf(" Stack is full");
	}
	
	else{
	printf("push element ::");
	scanf("%d",&val);
	stack[++top]=val;
	}	
}
void pop(){
	
	if(top == -1){
		printf("Stack is empty");
	}
	else{
		printf("popped of %d \n",stack[top--]);
	}
}
void show(){
	if(top >= 0){	
		printf("Stack elements :: \n");
		for(int i=top; i>=0; i--){
			printf("%d  ",stack[i]);
		}
	}
	else{
		printf("\n Stack is empty.");
	}
}
int main(){
	a:
	printf("1. push ::\n");
	printf("2. pop  ::\n");
	printf("3. show ::\n");
	printf("4. exit ::\n");
	
	while(1){
	printf("\n Enter your choice ::");
	int num;
	scanf("%d",&num);
	
	switch(num){
		case 1: push();
				break;	
				
		case 2: pop();
				break;
				 
		case 3: show();
				break;
				
		case 4: exit(0);
				
		default : printf("\n Invalid choice .. \n  please enter the correct number. \n");
		goto a;
	}
  }	
}