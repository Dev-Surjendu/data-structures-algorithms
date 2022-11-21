#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;

int main(){

	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter element for the root node:: ");
	scanf("%d",&ptr->data);
	
	if(root == NULL){
		ptr->left=NULL;
		ptr->right=NULL;
		root=ptr;
	}
	struct node* ptr1=(struct node*)malloc(sizeof(struct node));
	printf("Enter element for the left node:: ");
	scanf("%d",&ptr1->data);
	ptr1->left=NULL;
	ptr1->right=NULL;
	
	struct node* ptr2=(struct node*)malloc(sizeof(struct node));
	printf("Enter element for the left node:: ");
	scanf("%d",&ptr2->data);
	ptr2->left=NULL;
	ptr2->right=NULL;
	
	ptr->left=ptr1;
	ptr->right=ptr2;
}