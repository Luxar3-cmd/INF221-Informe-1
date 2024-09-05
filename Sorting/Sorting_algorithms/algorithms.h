#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Función para imprimir un arreglo

// Función para leer un arreglo desde un archivo
vector<int> read_arr(ifstream& data) {
    int size;
    data >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; ++i) {
        data >> arr[i];
    }

    return arr;
}

void printVector(vector<int> &arr) {
    for ( int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";    
    }
    cout << endl;
}

#endif // ALGORITHMS_H