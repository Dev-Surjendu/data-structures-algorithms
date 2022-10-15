#include<stdio.h>
int partition(int[],int,int);

void printArray(int arr[],int size){
	for(int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void QuickSort(int arr[],int low, int high){
	if(low<high){
		int position = partition(arr,low,high);
		QuickSort(arr,low,position-1);  // sort left subarray
		QuickSort(arr,position+1,high); // sort right subrarray
	}
}
int partition(int arr[],int low,int high){
	
	int pivot=arr[low];
	int start=low;
	int end=high;
	
	while(start<end){
		while(pivot >= arr[start]){
			start++;
		}
		while(pivot < arr[end]){
			end--;
		}
		if(start < end){
			// swap -> start & end
			int temp;
			temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;		
		}
	}
	// swap -> low(pivot) & end
	int	store=arr[low];
		arr[low]=arr[end];
		arr[end]=store;
		
	return end;
}
int main(){

//	int arr[]={7,6,10,5,9,2,1,15,7};
//	int n=9;
	
	printf("Enter size of the array :: ");
	int num;
	scanf("%d",&num);
	
	int arr[num];
	
	for(int i=0; i<num; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr[i]);
	}	
	printf("\nBefore sorting array elements are :->\n");
	printArray(arr,num);
	
	QuickSort(arr,0,num-1);

	printf("\nAfter sorting array elements are :->\n");
	printArray(arr,num);
	
	return 0;
}