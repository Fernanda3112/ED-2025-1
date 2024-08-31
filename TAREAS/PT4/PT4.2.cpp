#include <stdio.h>
#include <stdlib.h>  

struct alumno{
	char nombres[25];
	int edad;
	int calificacion;
};

float calcularPromedio(struct alumno **matriz, int n);


int main(){
	int rows;  
	int columns = 3;  
	struct alumno **matrix;
	int i,j;
	float prom;
	
	printf("\n Numero de alumnos: ");
	scanf("%d", &rows);
	
	struct alumno alumnos[rows];
	
	matrix = (struct alumno **) malloc(rows * sizeof(struct alumno *));  
	if(matrix==NULL){
		printf("\n Error");
		return 1;
	}
	
	for (int i = 0; i < rows; i++) {  
		matrix[i] = (struct alumno *) malloc(sizeof(struct alumno ));  
		if (matrix[i] == NULL) {
            printf("Error\n", i);
            return 1;
        }  
	}
	
	for(i=0; i<rows; i++){
		printf("\nIngrese el nombre: ");
    	scanf("%s", matrix[i]->nombres);
		printf("Ingrese la edad: ");
		scanf("%d", &matrix[i]->edad);
		printf("Ingrese la calificacion ");
		scanf("%d", &matrix[i]->calificacion);
		}
	

	printf("|  Nombre  |  Edad  |  Calificacion  |\n");
    for (i = 0; i < rows; i++) {
        printf("| %s |   %d   |   %d   |\n", matrix[i]->nombres, matrix[i]->edad, matrix[i]->calificacion);
    }
    
    
    prom = calcularPromedio(matrix, rows);
    printf("\nPromedio de calificacion: %.2f", prom);
	
    for (i = 0; i < rows; i++) {
        free(matrix[i]);  
    }
    free(matrix);  
    
    
	return 0;
}


float calcularPromedio(struct alumno **matrix, int n){
  float promedio = 0;
  int i;
  for(i=0;i<n;i++){
    promedio += matrix[i]->calificacion;
    
  }
  return(promedio/n);
}
