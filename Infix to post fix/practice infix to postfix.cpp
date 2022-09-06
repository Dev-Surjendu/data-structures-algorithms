#include<stdio.h>
#include<ctype.h> 
char stack[50];
int top=-1;

void push(char c ){
	stack[++top]=c;
}
int pop(){
	if(top==-1)
		return -1;
		
	else
	return stack[top--];
}
int priority(char ch){
	if(ch == '(')
		return 0;
		
	else if(ch == '+'|| ch == '-')
		return 1;
	
	else if(ch == '*' || ch == '/')
		return 2;
	
	else if(ch == '^')
		return 3;
}
int main(){
	char str[30];
	char *ptr,x;

	printf("Enter the value ::");
	gets(str);
	
	ptr=str;
	
	while (*ptr != '\0'){
		if(isalnum(*ptr)){
			printf("%c",*ptr);
		}
		else if(*ptr == '('){
			push(*ptr);
		}
		else if(*ptr ==  ')'){
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
	if(top != -1){
		printf("%c",pop());
	}
	return 0;
}