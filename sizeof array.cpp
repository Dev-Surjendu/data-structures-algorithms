#include<stdio.h>
// how to find size of an Array?
int main(){
	printf("Enter size of the 1st array :: ");
	int num;
	scanf("%d",&num);
	
	int arr[num];

	int size=sizeof(arr)/sizeof(arr[0]);
	printf("size of array is %d",size);
	
	return 0;
}