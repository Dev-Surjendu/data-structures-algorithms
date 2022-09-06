#include <stdio.h>
#include <string.h>

char stack[10][50];
int row=0;

void display(char *str){
	
	for(int i=row; i>=0; i--){
		for(int col=0; col<strlen(stack[i]); col++){
			
			printf("%c",stack[i][col]);
		}
		printf(" ");
	}
}
void push(char *str){

	int col=0;
	
	for(int i=0; i<strlen(str); i++){
		
		if(str[i] == ' '){
			row++;
			col=0;
		}
		else{
			stack[row][col]=str[i];
			col++;
		}	
	}
}
int main(){
	char str[40];
	printf("Enter the Text ::");
	scanf("%[^\n]s",str); // u can also use gets(str) fun
//  also - %[^\n]%*c
	push(str);
	display(str);
}