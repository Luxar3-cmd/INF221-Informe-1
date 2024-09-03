#include <iostream>
#include <vector>  // Incluyendo la cabecera vector

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

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> Arreglo = {5, 2, 4, 6, 1, 3};
    int n = Arreglo.size();
    
    cout << "Array original:\n";
    printArray(Arreglo);

    insertion_sort(Arreglo, n);
    
    cout << "Array ordenado:\n";
    printArray(Arreglo);

    return 0;
}
