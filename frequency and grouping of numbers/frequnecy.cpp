#include<stdio.h>
#include<stdlib.h>
int main(){
	int *arr;
	
	printf("Enter the size of te array ::");
	int size;
	scanf("%d",&size);
	
	arr=(int*)malloc(size*sizeof(int));
	
	for(int i=0; i<size; i++){
		scanf("%d",&arr[i]);
	}
	
	int min=arr[0];
	int max=arr[0];
	
	for(int i=0; i<size; i++){
		if(arr[i]<min)
			min=arr[i];
		else if(arr[i]>max)
			max=arr[i];
	}
	printf("%d %d\n",max,min);
	
	int min_fin = min-(min%10);
	int max_fin = (max-(max%10))+10;
	int count=0,j;	
	
	printf(" Group    Frequency");
	for(int i=min_fin; i<=max_fin; i+=10){
		int start = i;
		int end = i+10;
		
		for(j=0; j<size; j++){
			if(arr[j]>=start && arr[j]<=end){
				count++;
			}
		}
		if(count>0)
		printf("\n%d %d :: %d ",start,end,count);
		
		count=0;
	}
}