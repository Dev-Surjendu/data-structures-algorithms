//  [ difference ]

//  by default value of the malloc fun is garbage otherside,
//  by default value of  calloc fun is 0
// 	memory allocation
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr,num;
	printf("Enter the size of array you want to create ::");
	scanf("%d",&num);
	
	ptr=(int*)malloc(num*sizeof(int));  // ptr = (type*) malloc(n/size*sizeof(type)) 

	for(int i=0; i<num; i++){
		printf("Enter the value no %d of this array ::",i+1);
		scanf("%d",&ptr[i]);
	}
								
	for(int i=0; i<num+1; i++){  //  by default value will be garbage
		printf("The value at %d of this array is %d\n",i+1,ptr[i]);
	}

	return 0;
}