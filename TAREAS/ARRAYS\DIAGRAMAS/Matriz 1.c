//Matriz 1
#include <stdio.h>

int main() {
    int i, j;
    int fila = 6;
    int columna = 4;
    char matriz[6][4];
    
    // Primera fila
    for(i=0; i <= 0; i++) {
        for (j=0; j<columna; j++){
            matriz[i][j] = '*';
        }
    }


    // Segunda fila 
    for(i=1; i<2; i++){
        for(j=columna - 1; j >= 0; j--){
            matriz[i][j] = '*';
        } 
    }

    // Tercera fila 
    for(i= 2; i<3; i++){
         for(j= 0; j < columna; j++){
            matriz[i][j] = '*';
        }
    }

    // Cuarta fila 
    for(i=3; i<4; i++){
        for(j =columna-1; j>= 0; j--){
            matriz[i][j] = '*';
        }
    }

    // Quinta fila 
    for(i =4; i<5; i++){
        for(j= 0; j<columna; j++){
            matriz[i][j] = '*';
        }
    }

    // Sexta fila 
    for(i=5; i< 6; i++){
        for(j =columna-1; j >= 0; j--){
            matriz[i][j] = '*';
        }
    }

    // Imprimir la matriz
    for (i=0; i< fila; i++) {
        for (j=0; j<columna; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

