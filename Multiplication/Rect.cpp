#include <bits/stdc++.h>
#include "matrix_methods.h"
#include "tmatrix_mult.h"     // Multiplicación optimizada con transposición
#include "matrix_mult.h"      // Algoritmo estándar de multiplicación

using namespace std;
#define matrix vector<vector<int> >

int main() {
    ifstream data("Datasets_Matrix/Rect_matrix.txt");
    ofstream csv_file("Mult_times/Rect1.csv");
    csv_file << "N°Filas A,N°Columnas A,N°Columnas B,Tmatrix_mult,Matrix_mult" << endl;


    if (!data.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    if (!csv_file.is_open()) {
        cerr << "Error abriendo el archivo CSV." << endl;
        return 1;
    }

    // Leer la matriz completa desde el archivo una sola vez
    matrix large_matrix1 = read_matrixs(data);
    matrix large_matrix2 = read_matrixs(data);
    data.close();

    if (large_matrix1.empty() || large_matrix2.empty()) {
        cout << "Ninguna matriz encontrada en el archivo." << endl;
        return 1;
    }

    int rowA = 2;
    int colA = 1;
    int colB = 3;
    // Iterar sobre diferentes tamaños rectangulares para las matrices
    for (int iteracion = 0; iteracion < 200; iteracion++) {
        matrix A = get_submatrix(large_matrix1, rowA, colA);
        matrix B = get_submatrix(large_matrix2, colA, colB);

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

        csv_file << rowA << "," << colA << "," << colB << "," << duration1.count() << "," << duration2.count() << endl;
        rowA += 3;
        colA += 3;
        colB += 3;
    }
    csv_file.close();
    return 0;
}
