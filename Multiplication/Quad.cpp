#include <bits/stdc++.h>
#include "matrix_methods.h"
#include "tmatrix_mult.h"
#include "matrix_mult.h"



using namespace std;
#define matrix vector<vector<int> >

int main() {
    ifstream data("Datasets_Matrix/big_matrix.txt");
    ofstream csv_output("Mult_times/Quad1.csv");
    

    if ( !data.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    if (!csv_output.is_open()) {
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
    
    // Escribir encabezado del archivo CSV
    csv_output << "n,Matrix_mult,Tmatrix_mult" << endl;

    //Iterar sobre diferentes tamaños de bloque
    for ( int size = 2; size <= 500; size+=2) {
        //Obtener submatrices de tamaño size x size
        matrix m1 = get_submatrix(large_matrix1, size, size);
        matrix m2 = get_submatrix(large_matrix2, size, size);

        // --- Multiplicación estándar ---
        auto start1 = chrono::high_resolution_clock::now();
        matrix result_standard = matrix_mult(m1, m2);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

        // --- Multiplicación de matrices con traspuesta  ---
        auto start2 = chrono::high_resolution_clock::now();
        matrix result_Tmatrix = Tmatrix_mult(m1, m2);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

        csv_output << size << "," << duration1.count() << "," << duration2.count() << endl;

    }

    csv_output.close();
    return 0;
}