#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <bits/stdc++.h>
#include <algorithms.h>

using namespace std;

void insertion_sort(vector<int>& arr, int size) {
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