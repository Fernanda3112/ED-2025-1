#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int i;
	int *pv;
	int cuenta[] = {3, 2, 1, 0, 4, 4, 5, 5, 6};
	int ultimoDigito = cuenta[8];
	
	pv = (int*) malloc(10 * sizeof(int));  
	
	if (pv == NULL) {
		printf("Error \n");
		return 1;
    }
	
for(i = 0; i < 10; i++) {  
	pv[i] = 20 - (i * 2);   

}

	for(i=0; i<10; i++) {  
		printf(" %d", pv[i] );
			
	}
	
	printf("\nNumero de cuenta: ");
	for(i=0; i<9; i++){
		printf("%d", cuenta[i] );
	}
	
	
	if(	ultimoDigito<10){
		pv[ultimoDigito]= -1;
	}
	
	
	printf("\n");
	
	for(i=0; i<10; i++) {  
		printf(" %d", pv[i] );
			
	}
	printf("\n");
	system("pause");
	free(pv);
	
	
	return 0;
}
