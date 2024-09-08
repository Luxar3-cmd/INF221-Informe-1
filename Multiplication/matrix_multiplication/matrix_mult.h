#ifndef MATRIX_MULT_CPP
#define MATRIX_MULT_CPP

#include <bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int> >


/**
 * Suposiciones del programa: 
 * - Las matrices ingresadas tienen siempre una estructura correcta (rectangular).
 * - La multiplicación se puede llevar a cabo si las columnas de la primera matriz (m1) coinciden con las filas de la segunda matriz (m2), es decir, FC == SR.
 */

/**
 * @brief Multiplica dos matrices de cualquier tamaño
 * 
 * Esta función toma dos matrices m1 y m2 como parámetros, y realiza la multiplicación 
 * matricial entre ambas, retornando la matriz resultante.
 * 
 * Supone que el número de columnas de m1 coincide con el número de filas de m2.
 * La matriz resultante tendrá tantas filas como m1 y tantas columnas como m2.
 * 
 * @param m1 Matriz A de tamaño FR x FC (FR filas y FC columnas).
 * @param m2 Matriz B de tamaño SR x SC (SR filas y SC columnas).
 * @return matrix Matriz resultante de la multiplicación de m1 y m2, de tamaño FR x SC.
 */
matrix matrix_mult(matrix& m1, matrix& m2){
    int FR, FC, SR, SC;
    FR = m1.size(); //Cantidad de filas primera matriz
    FC = m1[0].size(); //Cantidad de columnas primera matriz
    SR = m2.size(); //Cantidad de filas segunda matriz
    SC = m2[0].size(); //Cantidad de columnas segunda matriz
    matrix result(FR,vector<int>(SC,0)); //La matriz resultante tiene FR * SC casillas.

    for ( int i = 0; i < FR; ++i) {
        for ( int j = 0; j < SC; ++j) {
            for ( int k = 0; k < FC; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    
    return result;
}


#endif // MATRIX_MULT_CPP



