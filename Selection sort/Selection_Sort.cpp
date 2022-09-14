#include<stdio.h>
int main(){
	printf("Enter the size of the array :: ");
	int num;
	scanf("%d",&num);
	
	int arr[num];
	
	for(int i=0; i<num; i++){
		printf("Enter %dno -> ",i+1);
		scanf("%d",&arr[i]);
	}
	int temp,min;
	for(int i=0; i<num-1; i++){
		min=i;
		for(int j=i+1; j<num; j++){
			if(arr[min]>arr[j]){
				min=j;// storing index position
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	for(int i=0; i<num; i++){
		printf("%d\n",arr[i]);
	}
}