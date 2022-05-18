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
    for(int i = 0; i < n; i ++){
        arr[i] = (rand() % ((n* 2) + 1) ) - (n / 2);
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
int len(int * arr){
    return  sizeof(arr) / sizeof(arr[0]);
}

int sum(int * arr){
    int sum = 0;
    for(int i = 0; i < len(arr); i++){
        sum += arr[i];
    }
    return sum;
}

int * middlecalc(int  * arr,int mitad){

    return arr;
}

int * maxarray(int * left,int * middle,int * right){
    int sumleft = sum(left);
    int summiddle = sum(middle);
    int sumrigth = sum(right);

    if(sumleft > summiddle){
        if(sumleft > sumrigth){
            return left;
        } else {
            return right;
        }
    } else if(sumrigth > summiddle){
        return right;
    }
    return middle;
}

int * vectormax(int * arr){
    // caso mas basico, cuando tiene solo eleento
    if(len(arr) == 1){
        // caso base
        return arr; // cuando es un solo elemento el elementos mas grande es el mismo.
    }
    // dividimos el problema en mas pequeños
    int middle = len(arr) / 2;
    int * arrayleft = subarray(arr, 0, middle);
    int * arrayright = subarray(arr, middle, len(arr));

    // mandamos a llamar a si mismo para eocntrar la solucion
    // sin embargo, tenemos que considerar  que tenemos que tres posibles soluciones
    // uno donde el maximo este a la izquierda y otro donde este a la derehca,
    // por utlimo tenemos el caso donde se ecuentre en medio
    int * maxleft = vectormax(arrayleft);
    int * maxright = vectormax(arrayright);
    //int * maxmiddle = middlecalc(arr, middle);
    // por ultimo combinamos retornarno el arreglo maximo
    //return maxarray(maxleft,maxmiddle,maxright);
}

int main() {
    int n = 10;
    int * arr = newarray(n);

    int * max = vectormax(arr);

    printf("Arreglo original");
    printarray(arr,n);
    printf("\nSub arreglo mas grande\n");
    //printarray(max,len(max));

    return 0;
}
