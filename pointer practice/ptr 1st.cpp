#include<stdio.h>
int main(){
	int a=10;
	int *ptr=&a;
	// suppose &a = 12345  and &ptr = 58820
		
	printf("value of a = %d %d %d \n",a,*ptr,**&ptr);    //   **&ptr   = **58820 =    *12345 =      10 
	printf("address of a = %d %d %d\n",&a,ptr,*&ptr);   //     *&ptr   =  *58820 =     12345
	printf("address of ptr = %d\n",&ptr);
	
}