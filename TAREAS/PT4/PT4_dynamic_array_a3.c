#include <stdio.h>
#include <stdlib.h> 

int main(){
	char numCuenta[10];
	int filas = 9;
    int columnas;
	int i,j;
	int **matriz;
	int numeros;
	
	
	printf("\nDame el numero de cuneta: ");
	scanf("%9s", numCuenta);
	
	matriz = (int **) malloc(filas * sizeof(int *));
    if(matriz == NULL) {
        printf("\nError");
        return 1;
    }
    
    
    
     for (i = 0; i < filas; i++) {
        numeros = numCuenta[i] - '0'; 
        matriz[i] = (int *) malloc(numeros * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error");
          
        }

        // Rellenar las filas con los números 
        for (int j = 0; j < numeros; j++) {
            matriz[i][j] = numeros;
        }
    }

    // Imprimir la matriz
    for (i = 0; i <9; i++) {
        for (j = 0; j <(numCuenta[i] - '0'); j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

