#include<stdio.h>
/* suppose =   arr1 -> 2 1 0 5
			   arr2 -> 9 3 7 4 6
   then output will be -> 0 1 2 3 4 5 6 7 9 */
	   
void mergesort(int arr1[],int arr2[],int size1,int size2){
	int i,j,k;
	i=j=k=0;
	int size=size1+size2;
	int mergesort[size];
	
	while(i<size1 && j<size2){
		if(arr1[i]>arr2[j]){
			mergesort[k++]=arr2[j++];	
		}
		else
			mergesort[k++]=arr1[i++];
	}
	while(i<size1){
		mergesort[k++]=arr1[i++];
	}
	while(j<size2){
		mergesort[k++]=arr2[j++];
	}
	for(int i=0; i<size; i++){
		printf("%d\n",mergesort[i]);
	}
}
int main(){
	printf("Enter size of the 1st array :: ");
	int num1;
	scanf("%d",&num1);
	
	int arr_1[num1];
	
	for(int i=0; i<num1; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr_1[i]);
	}
	printf("Enter size of the 2nd array :: ");
	int num2;
	scanf("%d",&num2);
	
	int arr_2[num2];
	
	for(int i=0; i<num2; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr_2[i]);
	}
	int temp;
	for(int i=0; i<num1-1; i++){
		for(int j=i+1; j<num1; j++){
			if(arr_1[i]>arr_1[j]){
				temp=arr_1[i];
				arr_1[i]=arr_1[j];
				arr_1[j]=temp;
			}
		}
	}
	for(int i=0; i<num2-1; i++){
		for(int j=i+1; j<num2; j++){
			if(arr_2[i]>arr_2[j]){
				temp=arr_2[i];
				arr_2[i]=arr_2[j];
				arr_2[j]=temp;
			}
		}
	}
	mergesort(arr_1,arr_2,num1,num2);
}