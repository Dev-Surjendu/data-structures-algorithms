// increase size of the array using realloc fun

#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr,num;
	
	printf("Enter the size of array you want to create :::");
	scanf("%d",&num);
	
	ptr=(int*)calloc(num,sizeof(int));    

	for(int i=0; i<num; i++){
		printf("Enter the value no %d of this array ::",i+1);
		scanf("%d",&ptr[i]);
	}
	
	printf("Enter the size of the new array you want to create :::");
	scanf("%d",&num);
	
	ptr=(int*)realloc(ptr,num*sizeof(int));    // here we use realloc fun
	
	for(int i=0; i<num; i++){
		printf("Enter the value no %d of this array ::",i+1);
		scanf("%d",&ptr[i]);
	}
	
	for(int i=0; i<num; i++){ 
		printf("The value at %d of this array is %d\n",i+1,ptr[i]);
	}
	
	free(ptr);  // we can free the previous memory using free function 
	
	for(int i=0; i<num; i++){ 
		printf("The value at %d of this array is %d\n",i+1,ptr[i]);
	}
	return 0;
}