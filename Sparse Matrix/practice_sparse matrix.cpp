#include<stdio.h>

int main(){
		
	int row,col;
	a:
	printf("Enter the row size ::");
	scanf("%d",&row);
	
	printf("Enter the col size ::");
	scanf("%d",&col);
	
	int arr[row][col];
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d %d = ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	int zero;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(arr[i][j] == 0)
			zero++;
		}
	}
	if(zero > ((row*col)/2)){
	
	int non_zero=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(arr[i][j] != 0)
			non_zero++;
		}
	}
	
	int sparse_matrix[3][non_zero],k=0;
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			
			if(arr[i][j] != 0){
				sparse_matrix[0][k]=i;
				sparse_matrix[1][k]=j;
				sparse_matrix[2][k]=arr[i][j];
				
				k++;
			}	
		}
	}
	printf("Sparse Matrix :: \n");
	for(int i=0; i<3; i++){
		for(int j=0; j<non_zero; j++){
			printf("%d ",sparse_matrix[i][j]);
		}
		printf("\n");
	}
 	}
	else{
		printf("\n\nThis matrix is not sparse matrix..\nPlease enter correct elements ::\n\n");
 		goto a;
	}
	return 0;
}