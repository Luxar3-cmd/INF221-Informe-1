#ifndef TMATRIX_MULT_CPP
#define TMATRIX_MULT_CPP

#include <bits/stdc++.h>

using namespace std;

#define matrix vector<vector<int>>

/*
    En este programa, a diferencia de matrix_mult.cpp, se tranpone la segunda matriz
    antes de realizar la multiplicación. Esto mejora la eficiencia del acceso a la memoria
    al acceder de forma secuencial a los elementos, mejorando la localidad espacial.
*/

/*
Suposiciónes del programa:
- Las matrices ingresadas tienen siempre una estructura correcta (rectangular).
- La multiplicación es válida si el número de columnas de la primera matriz es igual
al número de filas de la segunda matriz.
*/

/**
 * @brief Transpone una matriz.
 * 
 * Esta función toma una matriz de tamaño "n x m" y retorna su transpuesta, de tamaño "m x n".
 * Donde las filas se convierten en columnas.
 * 
 * @param mat La matriz de entrada a transponer.
 * @return matrix Matriz traspuesta de la matriz de entrada.
 */
matrix transpose (const matrix& mat) {
    int filas = mat.size();
    int columnas = mat[0].size();
    matrix trans(filas, vector<int>(columnas));
    for ( int i = 0; i < filas; i++) {
        for ( int j = 0; j < columnas; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    return trans;
}


/**
 * @brief Multiplica dos matrices de cualquier tamaño con la optimización de transponer la segunda matriz.
 * 
 * Esta función realiza la multiplicación de dos matrices 'm1' y 'm2'. Antes de la multiplicación, transpone la matriz 'm2 para mejorar el acceso a los elementos, lo que aumenta la eficiencia de la multiplicación.
 * 
 * @param m1 Primera matriz (A) de tamaño FR x FC (FR filas y FC columnas).
 * @param m2 Segunda matriz (B) de tamaño SR x SC (SR filas y SC columnas).
 * @return matrix Matriz resultante de la multiplicación de m1 y m2, de tamaño FR x SC.
 */
matrix Tmatrix_mult(matrix& m1, matrix& m2){
    int FR, FC, SR, SC;
    FR = m1.size(); //Cantidad de filas primera matriz
    FC = m1[0].size(); //Cantidad de columnas primera matriz
    SR = m2.size(); //Cantidad de filas segunda matriz
    SC = m2[0].size(); //Cantidad de columnas segunda matriz

    matrix m2T = transpose(m2);

    matrix result(FR,vector<int>(SC,0)); //La matriz resultante tiene FR * SC casillas.

    for ( int i = 0; i < FR; ++i) {
        for ( int j = 0; j < SC; ++j) {
            for ( int k = 0; k < FC; ++k) {
                result[i][j] += m1[i][k] * m2[j][k];
            }
        }
    }
    return result;
}


#endif // TMATRIX_MULT_CPP