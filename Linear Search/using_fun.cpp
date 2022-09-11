#include<stdio.h>
int linear_Search(int arr[],int size,int val){
	for(int i=0; i<size; i++){
		if(arr[i]==val){
			return i;
		}
	}
	return 0;
}
int main(){
	printf("Enter the size of the array :: ");
	int num;
	scanf("%d",&num);
	
	int arr[num];
	
	for(int i=0; i<num; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr[i]);
	}
	a:
	printf("\nEnter element to search :: ");
	int val;
	scanf("%d",&val);
	
	int search=linear_Search(arr,num,val);
	if(search == 0){
		printf("\nElement not found\n");
		goto a;
	}
	else{
		printf("\nElement found at index %d",search);
	}
}