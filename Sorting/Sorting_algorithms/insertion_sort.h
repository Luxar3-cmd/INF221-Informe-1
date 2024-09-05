#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <bits/stdc++.h>
#include <algorithms.h>

using namespace std;


/**
 * @brief Ordena un vector de enteros utilizando el algoritmo de ordenamiento por inserción.
 * 
 * Este algoritmo recorre el arreglo y va colocando cada elemento en su posición correcta dentro de la parte ya ordenada del arreglo. La complejidad de este algoritmo es O(n^2) en el peor caso, pero puede ser eficiente para arreglos pequeños o casi ordenados.
 * 
 * @param arr Vector de enteros a ordenar (pasado por referencia).
 */
void insertion_sort(vector<int>& arr) {
    int size = arr.size();
    // Recorrer el array desde el segundo elemento
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos de arr[0..i-1], que son mayores que key, una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

#endif // INSERTION_SORT