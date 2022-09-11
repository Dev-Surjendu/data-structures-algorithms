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
	a:
	printf("\nEnter element to search :: ");
	int val;
	scanf("%d",&val);
	
	int j,count=0;
	for(j=0; j<num; j++){
		if(arr[j]==val){
			count++;
			break;
		}
	}
	if(count == 0){
		printf("\nElement not found\n");
		goto a;
	}
	else{
		printf("\nElement found at index %d",j);
	}
}