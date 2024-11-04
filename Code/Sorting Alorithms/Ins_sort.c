#include<stdio.h>
#include<stdlib.h>

int main(){
	int cantidad;
	printf("Numbers to sort: ");
	scanf("%d", &cantidad);
	
	int num[cantidad];
	int i, position, index; 
	
	for(i=0;i<cantidad; i++){
		printf("Number %d: ", i+1);
		scanf("%d", &num[i]);
	}	
	
	for(i=0;i<cantidad;i++){
		position=i;
		index=num[i];
		
		while((position>0)&&(num[position-1]> index)){
			num[position]= num[position-1];
			position--;
		}
		num[position]=index;	
	}
	system("cls");
	printf("\nOrdered numbers\n");
	for(i=0;i<cantidad;i++){
		printf(" %d |",num[i] );
	}
}
