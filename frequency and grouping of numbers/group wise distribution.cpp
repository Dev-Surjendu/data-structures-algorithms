#include<stdio.h>  

int startingVal(int num) {
    return (num / 10) * 10;
}

int main()    
{  
    int n;
    printf("Enter the size of the array ::");
	scanf("%d",&n);  
	 
	int arr[n];
	     
    for (int i=0; i<n; i++) {
		printf("Enter %d number :: \n",i+1);     
        scanf("%d",&arr[i]);     
    }      
            
    for (int i = 0; i < n; i++) {     
        for (int j = i+1; j < n; j++) { 
          if(arr[i] > arr[j]) {    
            int temp = arr[i];    
              arr[i] = arr[j];    
              arr[j] = temp;    
          }     
        }     
    }  
    
	int lastStart;
	
	for(int i=0; i<n; i++){
    	int start = startingVal(arr[i]); 
    	int end = start+9;  
        
        if(i == 0 || lastStart != start ) {
            printf("\n%d %d = ", start, end);
        }
        printf("%d ", arr[i]);
    	lastStart = start;
    	
    }
    return 0;
}