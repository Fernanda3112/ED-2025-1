//Matriz 4
#include <stdio.h>

int main() {
	int i,j;
    int fila = 3;
    int columna = 4;
    char matriz[3][4];

   for(i=fila-1; i>=0 ; i--) {
      for (j = columna-1; j >=0; j--){
          matriz[i][j] = '*';
      }
   }
  
    // Imprimir la matriz
    for (i = 0; i <fila; i++) {
        for(j = 0; j < columna; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

