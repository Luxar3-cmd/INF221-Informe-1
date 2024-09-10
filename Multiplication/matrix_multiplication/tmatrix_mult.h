#ifndef TMATRIX_MULT_CPP
#define TMATRIX_MULT_CPP

#include <bits/stdc++.h>

using namespace std;

#define matrix vector<vector<int> >

/*
    En este programa, a diferencia de matrix_mult.cpp, se traspone la segunda matriz
    antes de realizar la multiplicación.
*/


/**
 * @brief Traspone una matriz.
 * 
 * Esta función toma una matriz de tamaño "n x m" y retorna su traspuesta, de tamaño "m x n".
 * Donde las filas se convierten en columnas.
 * 
 * @param mat La matriz de entrada a transponer.
 * @return matrix Matriz traspuesta de la matriz de entrada.
 */
matrix transpose (matrix& mat) {
    int filas = mat.size();
    int columnas = mat[0].size();
    matrix T(columnas, vector<int>(filas));
    for ( int i = 0; i < filas; i++) {
        for ( int j = 0; j < columnas; j++) {
            T[j][i] = mat[i][j];
        }
    }
    return T;
}


/**
 * @brief Multiplica dos matrices de cualquier tamaño con la optimización de trasponer la segunda matriz.
 * 
 * Esta función realiza la multiplicación de dos matrices 'm1' y 'm2'. Antes de la multiplicación, traspone la matriz 'm2 para mejorar el acceso a los elementos, lo que aumenta la eficiencia de la multiplicación.
 * 
 * @param m1 Primera matriz (A) de tamaño FR x FC (FR filas y FC columnas).
 * @param m2 Segunda matriz (B) de tamaño SR x SC (SR filas y SC columnas).
 * @return matrix Matriz resultante de la multiplicación de m1 y m2, de tamaño FR x SC.
 */
matrix Tmatrix_mult(matrix& m1, matrix& m2){
    int filasA = m1.size(); //Cantidad de filas primera matriz
    int columnasA = m1[0].size(); //Cantidad de columnas primera matriz
    int columnasB = m2[0].size(); //Cantidad de columnas segunda matriz


    if (columnasA != m2.size()) {
        cerr << "Error: Las columnas de la primera matriz deben coincidir con las filas de la segunda matriz." << endl;
        return matrix();
    }
    matrix Tm2 = transpose(m2);

    matrix result(filasA,vector<int>(columnasB,0)); //La matriz resultante tiene FR * SC casillas.

    for ( int i = 0; i < filasA; ++i) {
        for ( int j = 0; j < columnasB; ++j) {
            for ( int k = 0; k < columnasA; ++k) {
                result[i][j] += m1[i][k] * Tm2[j][k];
            }
        }
    }

    return result;
}


#endif // TMATRIX_MULT_CPP