#ifndef MATRIX_MULT_CPP
#define MATRIX_MULT_CPP

#include <bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int>>


/*
Suposiciónes del programa:
- Las matrices ingresadas tienen siempre una estructura correcta, significa que las rectangulares están en el orden correcto.
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



