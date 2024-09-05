#ifndef MERGE_SORT
#define MERGE_SORT

#include <bits/stdc++.h>
#include "algorithms.h"
using namespace std;


/**
 * @brief Combina dos subarreglos ordenados en un solo arreglo ordenado.
 * 
 * La función toma un arreglo dividido en dos subarreglos ordenados y los combina en un solo arreglo ordenado.
 * 
 * @param arr Arreglo principal.
 * @param left Índice del primer elemento del arreglo.
 * @param mid Índice del elemento medio del arreglo.
 * @param right Índice del último elemento del arreglo.
 */
void merge(vector<int> &arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;
    //Creación de los arreglos auxiliares
    vector<int> L(n1), R(n2);
    //Copia de los valores
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for ( int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    //Inicialización de los indices
    int l = 0, r = 0;
    int k = left;
    while ( l < n1 && r < n2) {
        if (L[l] <= R[r] ) {
            arr[k] = L[l];
            l++;
        } else {
            arr[k] = R[r]; 
            r++;
        }
        k++;
    }
    
    while ( l < n1 ) {
        arr[k] = L[l];
        l++;
        k++;
    }

    while ( r < n2 ) {
        arr[k] = R[r];
        r++;
        k++;
    }
}

/**
 * @brief Función recursiva que implementa el algoritmo Mergo Sort.
 * 
 * Divide el arreglo en dos mitades, las ordena recursivamente y luego las fusiona
 * utilizando la función 'merge'.
 *  
 * @param arr Vector de enteros a ordenar (pasado por referencia).
 * @param left Índice del primer elemento del arreglo.
 * @param right Índice del último elemento del arreglo.
 */
void merge_sort(vector<int> &arr, int left, int right) {
    if (left >= right) 
        return;

    int mid = left + (right-left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1 , right);
    merge(arr, left, mid, right);
}

#endif // MERGE_SORT