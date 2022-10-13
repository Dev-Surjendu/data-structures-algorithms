#include<stdio.h>
int *Bubble_sort(int *arr){
	int temp;
	for(int i=0; i<sizeof(arr)-1; i++){
		for(int j=i+1; j<sizeof(arr); i++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}			
		}
	}
	return arr;
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
	int *new_arr;
	new_arr=Bubble_sort(arr);
	
	for(int i=0; i<num; i++){
		printf("%d\n",new_arr[i]);
	}
}