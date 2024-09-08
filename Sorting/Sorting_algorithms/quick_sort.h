#ifndef QUICK_SORT
#define QUICK_SORT

#include <bits/stdc++.h>
#include "algorithms.h"

using namespace std;

/**
 * @brief Función auxiliar que realiza la partición del arreglo.
 * 
 * La función selecciona un elemento pivote (el último en este caso) y reorganiza el
 * arreglo de forma que los elementos menores al pivote se colocan a la izquierda y
 * los mayores a la derecha. Retorna el índice del pivote.
 * 
 * @param arr Referencia al vector de enteros.
 * @param start Índice de inicio de la porción del arreglo a particionar.
 * @param end Índice final de la porción del arreglo a particionar (pivote).
 * @return int El índice del pivote una vez que el arreglo ha sido particionado.
 */
int partition(vector<int>& arr, int start, int end) {
    //Define pivote al final
    int pivot = arr[end];
    int i = start - 1;
    for ( int j = start ; j < end  ; j++ ){
        if( arr[j] < pivot ) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end]=temp;
    return i;
}

/**
 * @brief Implementa el algoritmo QuickSort.
 * 
 * QuickSort es un algoritmo de ordenación eficiente de complejidad O(n log n) en promedio.
 * Divide el arreglo en dos partes en torno a un pivote y las ordena recursivamente.
 * 
 * @param arr Referencia al vector de enteros a ordenar.
 * @param start Índice inicial de la porción del arreglo a ordenar.
 * @param end Índice final de la porción del arreglo a ordenar.
 */
void QuickSort(vector<int>& arr, int start, int end) {
    if ( start < end) {
        int pivot = partition(arr, start, end);

        QuickSort(arr,start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }

}

#endif //QUICK_SORT