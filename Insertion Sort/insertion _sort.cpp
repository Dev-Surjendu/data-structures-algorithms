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
	
	int next,j;
	for(int i=1; i<num; i++){
		next=arr[i];
		j=i-1;
	
		while(j>=0 && arr[j]>next){
			arr[j+1]=arr[j];
			j--;		
		}
		arr[j+1]=next;
	}
	for(int i=0; i<num; i++){
		printf("%d\n",arr[i]);
	}
}