#include<stdio.h>
int main(){
    int row,col,num;
    int magic_matrix[100][100];
	a:
    printf("Enter Array :: ");
    scanf("%d",&num);
    
	if(num%2 != 0){
		
    for(row=0; row<num; row++){
        for(col=0; col<num; col++){
            magic_matrix[row][col] = 0;
        }
    }
        row = num / 2;
        col = num - 1;
        
        for(int n=1;n<=num*num;n++){
            magic_matrix[row][col] = n;
            row = row-1;
            col = col+1;
            if(magic_matrix[row][col] != 0){
                col = col-2;
                row = row+1;
            }else if(row == -1 && col==num){
                row = 0;
                col = num-2;
            }else{
                if(row == -1){
                    row = num - 1;
                }else if(col == num){
                    col = 0;
                }
            }
        }
        for(row=0; row<num; row++){
            for(col=0; col<num; col++){
                printf("%d\t",magic_matrix[row][col]);
            }
            printf("\n");
        }
    } 
	else{
        printf("enter odd no only.\n\n");
        goto a;
    }
    return 0;
}