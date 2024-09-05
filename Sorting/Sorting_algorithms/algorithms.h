#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @brief Lee un vector de enteros desde un archivo de entrada.
 * 
 * El archivo debe contener en la primera línea el tamaño del arreglo, seguido por los elementos
 * del arreglo separados por espacios o saltos de línea.
 * 
 * @param data Referencia a un flujo de entrada (archivo) desde donde se leerán los datos.
 * @return vector<int> Vector de enteros con los valores leídos.
 */
vector<int> read_arr(ifstream& data, int n) {
    vector<int> arr(n);
    int size; 
    data >> size;
    for (int i = 0; i < n; ++i) {
        data >> arr[i];
        //Se va leyendo cada elemento del archivo y se guarda en el vector
    }

    return arr;
}

/**
 * @brief Imprime un vector de enteros en consola.
 * 
 * Esta función recibe un vector de enteros y lo imprime en consola, separando los elementos por un espacio.
 * 
 * @param arr Vector de enteros a imprimir.
 */
void printVector(vector<int> &arr) {
    for ( int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";    
    }
    cout << endl;
}

#endif // ALGORITHMS_H