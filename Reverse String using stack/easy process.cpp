#include<stdio.h>
#include<string.h>
char String[10][30];
int row=0;
int col=0;

void push(char str){
	if(str == ' '){
		row++;
		col=0;
	}
	else{
		String[row][col]=str;
		col++;
	}
}
void display(){
	for(int i=row; i>=0; i--){
		for(col=0; col<strlen(String[i]); col++){
			printf("%c",String[i][col]);
		}
		printf(" ");
	}
}
int main(){
	char str[50];
	
	printf("Enter the String ::");
	scanf("%[^\n]s",str);
	int len=strlen(str);
	
	for(int i=0; i<len; i++){
		push(str[i]);
	}
	display();
}