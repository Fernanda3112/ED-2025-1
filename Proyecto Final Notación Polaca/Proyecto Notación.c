#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "stack.h"

#define MAX_LENGTH 100

int orden(char operador);
int contar_espacios(const char *str);
char postfija(char infija[MAX_LENGTH], int espacios);
void invertir_cadena(char *str);
int prefija(char infija[MAX_LENGTH], int espacios);
 
int main() {
    char infija[MAX_LENGTH];
    
    printf("Ingrese la notacion infija: \n");
    scanf("%99[^\n]", infija);  // leer hasta el salto de línea
    
    printf("\n ____________");
    printf("\n Notacion infija: \n\n");
    printf("%s", infija);
    printf("\n ____________");
    // Contamor los espacios en la cadena
    int espacios = contar_espacios(infija);
    
    printf("\n Notacion postfija: \n\n");
    postfija(infija, espacios);
    printf("\n ____________");
    
    printf("\n Notacion prefija: \n\n");
    prefija(infija, espacios);
    
    
    return 0;
}

int orden(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    if (operador == '^') return 3;
    return 0;
}

// Función para contar los espacios en la cadena
int contar_espacios(const char *str) {
    int count = 0;
    
    // Recorremos la cadena hasta encontrar el final (character '\0')
    while (*str != '\0') {
        if (*str == ' ') {  // Verificamos si el carácter es un espacio
            count++;
        }
        str++;  // Avanzamos al siguiente carácter
    }
    
    return count;
}

// Conversión de notación infija a postfija
char postfija(char infija[MAX_LENGTH], int espacios){
	Stack stack;
	char *data;
	int i;
	
	stack_init(&stack, free);
	
	// Recorrer la cadena y detectar paréntesis y operadores
	for (i = 0; infija[i] != '\0'; i++) {
        char c = infija[i];
        
        if (c == '(') {
            // Si encontramos ( lo agregamos al stack
            if ((data = (char *)malloc(sizeof(char))) == NULL)
                return 1;
            *data = c;
            stack_push(&stack, data);
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Si encontramos un operador, se agrega al stack
            if ((data = (char *)malloc(sizeof(char))) == NULL)
                return 1;
                
            *data = c;
            stack_push(&stack, data);
        } else if (c == ')') {
            // Si encontramos un paréntesis de cierre, vaciamos el stack hasta encontrar un '('
            while (stack_size(&stack) > 0) {
                if (stack_pop(&stack, (void **)&data) != 0)
                    return 1;
                if (*data == '(') {
                    free(data);  // Liberamos el paréntesis de apertura
                    break;
                } else {
                    // Imprimimos el operador que está en el stack
                    printf("%c ", *data);
                    free(data);
                }
            }
        } else {
            // Si encontramos un carácter que no es operador ni paréntesis, lo imprimimos directamente
            printf("%c ", c);
        }
    }
    
    // Vaciar el stack restante, si lo hay
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, (void **)&data) == 0) {
            printf("%c ", *data);
            free(data);
        }
    }
    
    stack_destroy(&stack);  // Destruir el stack después de usarlo
    return 0;
 }
 
// Función auxiliar para invertir una cadena
void invertir_cadena(char *str) {
    int i, len = strlen(str);
    
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    
}

// Conversión a notación prefija
int prefija(char infija[MAX_LENGTH], int espacios) {
    char infija_invertida[MAX_LENGTH];
    char postfija_resultado[MAX_LENGTH];
    Stack stack;
    char *data;
    int i, pos = 0;

    strcpy(infija_invertida, infija);
    invertir_cadena(infija_invertida);
    
	 // Cambiar los paréntesis de apertura y cierre en la cadena invertida
    for (i = 0; infija_invertida[i] != '\0'; i++) {
        if (infija_invertida[i] == '(') {
            infija_invertida[i] = ')';
        } else if (infija_invertida[i] == ')') {
            infija_invertida[i] = '(';
        }
    }

    stack_init(&stack, free);

    for (i = 0; infija_invertida[i] != '\0'; i++) {
        char c = infija_invertida[i];

        if (isalnum(c)) {
            postfija_resultado[pos++] = c;
            postfija_resultado[pos++] = ' ';
        } else if (c == '(') {
            if ((data = (char *)malloc(sizeof(char))) == NULL) return 1;
            *data = c;
            stack_push(&stack, data);
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            if ((data = (char *)malloc(sizeof(char))) == NULL) return 1;
            *data = c;
            while (stack_size(&stack) > 0 && orden(*((char *)stack_peek(&stack))) >= orden(c)) {
                stack_pop(&stack, (void **)&data);
                postfija_resultado[pos++] = *data;
                postfija_resultado[pos++] = ' ';
                free(data);
            }
            stack_push(&stack, data);
        } else if (c == ')') {
            while (stack_size(&stack) > 0) {
                stack_pop(&stack, (void **)&data);
                if (*data == '(') {
                    free(data);
                    break;
                }
                postfija_resultado[pos++] = *data;
                postfija_resultado[pos++] = ' ';
                free(data);
            }
        }
    }

    while (stack_size(&stack) > 0) {
        stack_pop(&stack, (void **)&data);
        postfija_resultado[pos++] = *data;
        postfija_resultado[pos++] = ' ';
        free(data);
    }

    stack_destroy(&stack);

    postfija_resultado[pos] = '\0';
    invertir_cadena(postfija_resultado);

    printf("%s", postfija_resultado);
    return 0;
}
