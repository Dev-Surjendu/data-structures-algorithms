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
	int temp;
	for(int i=0; i<num-1; i++){
		for(int j=i+1; j<num; j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0; i<num; i++){
		printf("%d\n",arr[i]);
	}
}