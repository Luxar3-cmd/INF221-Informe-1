#include <bits/stdc++.h>
#include "algorithms.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main() {
    ifstream data("Datasets_sorting/ascendent.txt");
    ofstream csv_output("Sorting_times/ascendent_time.csv");  // Archivo CSV para los tiempos

    if (!data.is_open()) {
        cerr << "Error opening the data file" << endl;
        return 1;
    }

    if (!csv_output.is_open()) {
        cerr << "Error opening the CSV file" << endl;
        return 1;
    }

    // Escribir la cabecera del archivo CSV
    csv_output << "Block Size,Insertion Sort,Merge Sort,Quick Sort,STL Sort" << endl;

    // Control del tamaño del bloque usando potencias de 10
    int n = 1;  // Potencia inicial (10^1 = 10 elementos)

    // Definir límite de tamaño del bloque (por ejemplo, hasta 10^5)
    while (n <= 5) {  // Esto cubrirá desde 10^1 (10 elementos) hasta 10^5 (100000 elementos)

        // Calcular block_size como 10^n
        int block_size = pow(10, n);

        // Leer y ordenar 10 veces para cada tamaño de bloque
        for (int i = 0; i < 5; i++) {
            
            

            // Leer un bloque de datos
            vector<int> arr = read_arr(data, block_size);

            if (arr.empty()) {
                cerr << "Not enough data in file for block size: " << block_size << endl;
                break;
            }

            // Probar Insertion Sort
            vector<int> arr1 = arr;
            auto start1 = chrono::high_resolution_clock::now();
            insertion_sort(arr1);
            auto end1 = chrono::high_resolution_clock::now();
            auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

            // Probar Merge Sort
            vector<int> arr2 = arr;
            auto start2 = chrono::high_resolution_clock::now();
            merge_sort(arr2, 0, arr2.size() - 1);
            auto end2 = chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

            // Probar Quick Sort
            vector<int> arr3 = arr;
            auto start3 = chrono::high_resolution_clock::now();
            QuickSort(arr3, 0, arr3.size() - 1);
            auto end3 = chrono::high_resolution_clock::now();
            auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);

            // Probar Sort de STL
            vector<int> arr4 = arr;
            auto start4 = chrono::high_resolution_clock::now();
            sort(arr4.begin(), arr4.end());
            auto end4 = chrono::high_resolution_clock::now();
            auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);

            
            // Escribir los tiempos y el tamaño del bloque en el archivo CSV
            csv_output << block_size << "," << duration1.count() << "," << duration2.count() << "," << duration3.count() << "," << duration4.count() << endl;
            
            if ( block_size < 100) block_size += 10;
            else if ( block_size < 1000) block_size += 100;
            else if ( block_size < 10000) block_size += 1000;
            else block_size += 10000;
            
        }

        // Incrementar la potencia para el siguiente bloque (10, 100, 1000, etc.)
        n++;
    }

    data.close();
    csv_output.close();
    return 0;
}
