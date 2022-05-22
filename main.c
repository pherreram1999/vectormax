#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxint -1000000000

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
 *
 * @return
 */
int * inputarray(int n){
    int * arr =  (int *) malloc( n * sizeof(int));
    printf("Ingrese los valores para el nuevo arreglo =>\n");
    for(int i = 0; i < n; i++){
        printf("%d:\t",i + 1);
        scanf("%d",&arr[i]);
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


int sum(int * arr,int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int middlecalc(int  * arr,int middle,int max){
    int maxleft = maxint, maxrigth = maxint, sum = 0;
    for(int i = 0; i < middle; i++){
        sum += arr[i];
        if(sum > maxleft)
            maxleft = sum;
    }

    sum = 0;
    for(int i = middle; i < max; i++){
        sum += arr[i];
        if(sum > maxrigth)
            maxrigth = sum;
    }
    return maxleft + maxrigth;
}

int maxarray(int left,int middle,int rigth){
    if(left > middle){
        if(left > rigth){
            return left;
        } else {
            return rigth;
        }
    } else if(rigth > middle){
        return rigth;
    }
    return middle;
}

int vectormax(int * arr,int n){
    // caso mas basico, cuando tiene solo elemento

    if(n == 1){
        // caso base
        return arr[0]; // cuando es un solo elemento el elementos mas grande es el mismo.
    }
    // dividimos el problema en mas pequeños
    int middle = n / 2;
    // daddo que tenemos en redondeo, si tenemos residuo significa que que tenemos un arreglo impar
    // dado al redondeo de la de la division entera, perdemos un elemento del arreglo izquierdo, es por
    // que verificamo este caso para agregarselo a la longitud del arreglo derecho
    int lenrigth = (n % 2) == 0 ? middle : middle + 1;
    int * arrayleft = subarray(arr, 0, middle);
    int * arrayright = subarray(arr, middle,n);
    // mandamos a llamar a si mismo para eocntrar la solucion
    // sin embargo, tenemos que considerar  que tenemos que tres posibles soluciones
    // uno donde el maximo este a la izquierda y otro donde este a la derehca,
    // por utlimo tenemos el caso donde se ecuentre en medio
    int maxleft = vectormax(arrayleft,middle);
    int maxright = vectormax(arrayright,lenrigth);
    int maxmiddle = middlecalc(arr, middle,n);
    // por ultimo combinamos retornarno el arreglo maximo
    return maxarray(maxleft,maxmiddle,maxright);
}

int main() {
    int n = 5;
    int * arr = inputarray(n);
    printf("Datos ingresados:\n");
    printarray(arr,n);
    int max = vectormax(arr,n);
    printf("suma maxima: %d",max);
    return 0;
}
