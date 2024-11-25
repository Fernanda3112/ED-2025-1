//preferably use big arrays of numbers
#include <stdio.h>
#include <stdlib.h>

void quick(int array[], int min, int max){
        int i = min;
        int j = max;
        int temp;
        int mitad = array[(i + j)/2];

        do{
                while(array[i] < mitad && i < max)
                        i++;
                while(array[j] > mitad && j > min)
                        j--;
                if(i <= j){
                        temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                        i++;
                        j--;
                }
        }while(i <= j);

        if(min < j)
                quick(array, min, i - 1);
        if(i < max)
                quick(array, i + 1, max);
}

int main(){
        int size, a[100], i, j, k;

        printf("What size you want for the array? ");
        scanf("%d", &size);

        if(size > 100){
                printf("The maximum value is 100 \n");
        }else{
                for(i = 0; i < size; i++){
                        printf("array[%d] = ", i + 1);
                        scanf("%d", &a[i]);
                }
        }

        printf("ORIGINAL ARRAY \n");
        for(j = 0; j < size; j++){
                printf("%d \n", a[j]);
        }

        printf("ORDERED ARRAY \n");

        quick(a, 0, size - 1);

        for(k = 0; k < size; k++){
                printf("%d \n", a[k]);
        }

        return 0;
}