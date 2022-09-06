#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int String[30];
int top=-1;
void push(int val){
	String[++top]=val;
}
int pop(){
	return String[top--];
}
int main(){
	char str[20];
	char *ptr;
	int num1,num2,num3,num;
	printf("Enter the String ::");
	scanf("%[^\n]s",str);
	
	ptr=str;
	while(*ptr != '\0'){
		if(isdigit(*ptr)){
			int num=*ptr-48;
			push(num);	
		}
		else{
			num1=pop();
			num2=pop();
			
			switch(*ptr){
				case '+': num3=num1+num2;
						  break;
						  
				case '-': num3=num1-num2;
						  break;
						  
				case '*': num3=num1*num2;
						  break;
						  
				case '/': num3=num1/num2;
						  break;		  		  
			}
			push(num3);
		}
		ptr++;
	}
	printf("\n The result of expression %s = %d\n",str,pop());
}