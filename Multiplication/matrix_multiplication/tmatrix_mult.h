#ifndef TMATRIX_MULT_CPP
#define TMATRIX_MULT_CPP

#include <bits/stdc++.h>

using namespace std;

#define matrix vector<vector<int>>


/*
En este programa, a diferencia de matrx_mult.cpp transpone la segunda matriz. Esto para lograr un mejor acceso que se traduce en eficiencia.
*/

/*
Suposiciónes del programa:
- Las matrices ingresadas tienen siempre una estructura correcta, significa que las rectangulares están en el orden correcto.
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

matrix matrix_mult(matrix& m1, matrix& m2){
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