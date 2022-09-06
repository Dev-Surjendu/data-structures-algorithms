#include <stdio.h>
#include <ctype.h> // for isalnum fun

char stack[30];
int top = -1;

void push(char val){	
	stack[++top] = val;		
}
int pop(){
	if(top == -1)
		return -1;
	else
		return stack[top--];
}
int priority(char x){
	if(x == '(')
		return 0;
	else if(x == '+'||x == '-')
		return 1;
	else if(x == '*'||x == '/')
		return 2;
	else if(x == '^')
		return 3;		
}

int main(){
	char str[50];
	char *ptr,x;
	
	printf("Enter the value ::");
	gets(str);
	
	ptr=str;
	
	while(*ptr != '\0')
	{
		if(isalnum(*ptr))
			printf("%c",*ptr);
		else if(*ptr == '(' )
			push(*ptr);
		else if(*ptr == ')')
		{
			while((x=pop()) != '('){
				printf("%c",x);
			}
		}
		else{
			while(priority(stack[top]) >= priority(*ptr))
				printf("%c",pop());
			push(*ptr);		
		}		
		ptr++;
	}
	while(top != -1){
		printf("%c",pop());
	}
	return 0;
}