#include<stdio.h>
// swap
int main(){
	int a=10;
	int b=5;
	
	a=a+b; //10+5=15
	b=a-b; //15-5=10
	a=a-b; //15-10=5
	printf("a = %d \nb = %d",a,b);
}
