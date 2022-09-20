#include<stdio.h>
int main(){
	printf("Enter size of the 1st array :: ");
	int num1;
	scanf("%d",&num1);
	
	printf("Enter size of the 2nd array :: ");
	int num2;
	scanf("%d",&num2);
	
	int arr1[num1];
	int arr2[num2];
	
	printf("\nEnter elements for the 1st array :->\n\n");
	for(int i=0; i<num1; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr1[i]);
	}
	// sorting 1nd array
	int temp;
	for(int i=0; i<num1-1; i++){
		for(int j=i+1; j<num1; j++){
			if(arr1[i]>arr1[j]){
				temp=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=temp;
			}
		}
	}
	printf("\nEnter elements for the 2nd array :->\n\n");
	for(int i=0; i<num2; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr2[i]);
	}
	// sorting 2nd array
	int sort;
	for(int i=0; i<num2-1; i++){
		for(int j=i+1; j<num2; j++){
			if(arr2[i]>arr2[j]){
				sort=arr2[i];
				arr2[i]=arr2[j];
				arr2[j]=sort;
			}
		}
	}
	int size=num1+num2;
	int merge_sort[size];
	
	int i,j,k;
	i=j=k=0;
	
	while(i<num1 && j<num2){
		if(arr1[i]<arr2[j]){
			merge_sort[k++]=arr1[i++];
		}
		else{
			merge_sort[k++]=arr2[j++];
		}	
	}
	while(i<num1){
		merge_sort[k++]=arr1[i++];
	}
	while(j<num2){
		merge_sort[k++]=arr2[j++];		
	}
    printf("\nAfter sorting array elements are :->\n");
	for(int i=0; i<size; i++){
		printf("%d ",merge_sort[i]);
	}
	return 0;
}