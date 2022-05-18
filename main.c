#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Genera un arreglo dinamico segun en tamaño que se le pase, ya con valores cargados,
 * @param n
 * @return
 */
int * newarray(int n){
    int * arr =  (int *) malloc( n * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i ++){
        arr[i] = (rand() % (n + 1) ) - (n / 2);
    }
    return arr;
}

/**
 * Imprime un arreglo
 * @param arr
 * @param n
 */
void printarray(int * arr,int n){
    printf("Array => [");
    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i < (n - 1) )
            printf(", ");
    }
    printf("]\n");
}

/**
 * retorna un slice o un sub arreglo dinamico segun las posiciones dadas
 * @param arr
 * @param start
 * @param max
 * @return
 */
int * subarray(int * arr,int start, int max){
    int len = max - start;
    int * sub = (int *) malloc(len * sizeof(int));
    for(int i = 0; i < len; i++){
        sub[i] = arr[start];
        start++;
    }
    return sub;
}

/**
 * retorna la longitud de un arreglo dinamico
 * @param arr
 * @return
 */
int count(int * arr){
    return  sizeof(arr) / sizeof(arr[0]);
}


int * vectormax(int * arr){

}

int main() {
    int n = 10;
    int * arr = newarray(n);
    printarray(arr,n);


    return 0;
}
