#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

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

void merge_sort(vector<int> &arr, int left, int right) {
    if (left >= right) 
        return;

    int mid = left + (right-left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1 , right);
    merge(arr, left, mid, right);
}


void printVector(vector<int> &arr) {
    for ( int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";    
    }
    cout << endl;
}



int main () {
    vector<int> datos = {2,1,4,9,8,0,5};

    int size = datos.size();

    cout << "El vector dado es: \n";
    
    printVector(datos);

    merge_sort(datos, 0, size - 1);

    cout << "El vector ordenado es \n";

    printVector(datos);
    
    return 0; 
}