// contiguous allocation
// In calloc fun we use "," instead of "*" .
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr,num;
	
	printf("Enter the size of array you want to create :::");
	scanf("%d",&num);
	
	ptr=(int*)calloc(num,sizeof(int));   // ptr = (type*) calloc(n,sizeof(type)) 

	for(int i=0; i<num; i++){
		printf("Enter the value no %d of this array ::",i+1);
		scanf("%d",&ptr[i]);
	}
	
	for(int i=0; i<num+1; i++){ // by default value will be 0
		printf("The value at %d of this array is %d\n",i+1,ptr[i]);
	}
	return 0;
}