#include <bits/stdc++.h>
#include "matrix_methods.h"
#include "strassen.h"
#include "tmatrix_mult.h"
#include "matrix_mult.h"



using namespace std;
#define matrix vector<vector<int> >

int main() {
    ifstream data("Datasets_Matrix/big_matrix.txt");
    ofstream csv_output("Mult_times/test.csv");
    

    if ( !data.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    if (!csv_output.is_open()) {
        cerr << "Error opening the CSV file" << endl;
        return 1;
    }

    // Leer la matriz completa desde el archivo una sola vez
    matrix large_matrix = read_matrixs(data);
    if (large_matrix.empty()) {
        cout << "No matrix found in the file!" << endl;
        return 1;
    }
    
    csv_output << "n,Matrix_mult,Strassen,Tmatrix_mult" << endl;

    //Iterar sobre diferentes tamaños de bloque
    for ( int size = 2; size <= 500; size+=2) {
        //Obtener submatrices de tamaño size x size
        matrix m1 = get_submatrix(large_matrix, size, size);
        matrix m2 = get_submatrix(large_matrix, size, size);


        // --- Multiplicación estándar ---
        auto start1 = chrono::high_resolution_clock::now();
        matrix result_standard = matrix_mult(m1, m2);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);


        // --- Multiplicación con Strassen ---
        auto start2 = chrono::high_resolution_clock::now();
        matrix result_strassen = strassen(m1, m2);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);


        // --- Multiplicación con transpuesta ---
        auto start3 = chrono::high_resolution_clock::now();
        matrix result_tmatrix = Tmatrix_mult(m1, m2);
        auto end3 = chrono::high_resolution_clock::now();
        auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);


        csv_output << size << "," << duration1.count() << "," << duration2.count() << "," << duration3.count() << endl;
    }

    csv_output.close();
    data.close();
    return 0;
}