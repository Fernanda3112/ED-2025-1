//Matriz 2
#include <stdio.h>

int main() {
    int i,j;
    int fila = 6;
    int columna = 6;
    char matriz[6][6];

    //primer fila 
    for (j=0; j<columna; j++) {
        matriz[0][j] = '*';
    }
    
    //diagonal 
    for (i=1; i<fila-1; i++) {
        for (j = 0; j < columna; j++) {
            if (j +i == 5) {
                matriz[i][j] = '*';
            }
        }
    }

    //ultima fila 
    for (j=0; j<columna; j++) {
        matriz[5][j] = '*';
    }

    // Imprime la matriz
    for (i=0; i<fila; i++) {
        for (j=0; j<columna; j++) {
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

