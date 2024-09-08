#include <bits/stdc++.h>
#include "matrix_methods.h"
#include "tmatrix_mult.h"     // Multiplicación optimizada con transposición
#include "matrix_mult.h"      // Algoritmo estándar de multiplicación

using namespace std;
#define matrix vector<vector<int> >

int main() {
    ifstream data("Datasets_Matrix/big_matrix.txt");
    ofstream csv_file("matrix_multiplication/matrix_rectangular_multiplication_times.csv");
    csv_file << "N°Filas A,N°Columnas A,N°Columnas B,Tmatrix_mult,Matrix_mult\n";


    if (!data.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    if (!csv_file.is_open()) {
        cerr << "Error opening the CSV file" << endl;
        return 1;
    }

    // Leer la matriz completa desde el archivo una sola vez
    matrix large_matrix = read_matrixs(data);
    if (large_matrix.empty()) {
        cout << "No matrix found in the file!" << endl;
        return 1;
    }
    int rowA = 2;
    int colA = 1;
    int colB = 3;
    // Iterar sobre diferentes tamaños rectangulares para las matrices
    for (int incremento = 2; incremento <= 300; incremento += 2) {
        matrix A = get_submatrix(large_matrix, rowA, colA);
        matrix B = get_submatrix(large_matrix, colA, colB);
        cout << "Multiplicando matrices de tamaño: " << rowA << "x" << colA << " y " << colA << "x" << colB << endl;

        // Multiplicación de matrices con traspuesta
        auto start = chrono::high_resolution_clock::now();
        matrix result1 = Tmatrix_mult(A, B);
        auto end = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);

        // Multiplicación de matrices tradicional
        auto strart2 = chrono::high_resolution_clock::now();
        matrix result2 = matrix_mult(A, B);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - strart2);

        csv_file << rowA << "," << colA << "," << colB << "," << duration1.count() << "," << duration2.count() << "\n";
        break;
        rowA += incremento;
        colA += incremento;
        colB += incremento;
    }

    data.close();
    csv_file.close();
    return 0;
}
