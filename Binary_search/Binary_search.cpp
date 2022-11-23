#include<stdio.h>
int binary_Search(int arr[],int size,int val){
	int low=0;
	int high=size-1;
	
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid] == val){
			return mid;
		}
		if(arr[mid]<val){
			low = mid+1;
		}
		else{
			high = mid-1;
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
	int temp;
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nSorting the array ::\n");
	for(int i=0; i<num; i++){
		printf("%d ",arr[i]);	
	}
	a:
	printf("\n\nEnter element to search :: ");
	int val;
	scanf("%d",&val);

	int search = binary_Search(arr,num,val);
	
	if(search == 0){
		printf("Element not found\n");
		goto a;
	}
	else{
		printf("\nElement found at index %d",search);
	}
}	