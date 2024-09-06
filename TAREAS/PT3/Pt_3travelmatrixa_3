//Matriz 3
#include <stdio.h>

int main() {
	int i,j;
    int fila = 6;
    int columna = 6;
    char matriz[6][6];

    // ultima fila
    for (j = 0; j<columna; j++) {
        matriz[fila- 1][j] = '*';
    }

    // diagonal(derecha a izquierda)
    for (i=5; i>=1; i--) {
        for (j = 1; j < columna; j++) {
            if (j +i == 5) {
                matriz[i][j] = '*';
            }
        }
    }
    
    //primera fila
    for (j=0; j<columna; j++) {
        matriz[0][j] = '*';
    }

    // Imprime la matriz
    for (i=0; i<fila; i++) {
        for (j=0; j<columna; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

