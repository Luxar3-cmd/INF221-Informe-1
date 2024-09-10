#ifndef STRASSEN_CPP
#define STRASSEN_CPP

/* 
Este algoritmo de Strassen asume que las matrices de entrada son cuadradas
y que sus dimensiones son de la forma n x n. Esto evita problemas con la recursión 
y garantiza que las matrices se puedan dividir en submatrices más pequeñas de igual tamaño.
*/


#include <bits/stdc++.h>
#include "matrix_mult.h"

#define matrix vector<vector<int> >

using namespace std;

/**
 * @brief Suma dos matrices cuadradas de tamaño K y almacena el resultado en una tercera matriz.
 * 
 * 
 * @param a Primera matriz a sumar.
 * @param b Segunda matriz a sumar.
 * @param c Matriz donde se almacenará el resultado de la suma.
 * @param K Índice de división de las matrices a y b.
 */
void add(matrix& a, matrix& b, matrix& c, int K) {
    for ( int i = 0; i  < K; i++) {
        for ( int j = 0; j < K; j++) {
            c[i][j] = a[i][j] + b[i][j]; //Suma de los elementos correspondientes
        }
    }
}   

/**
 * @brief Resta dos matrices cuadradas de tamaño K y almacena el resultado en una tercera matriz.
 * 
 * 
 * @param a Primera matriz a restar.
 * @param b Segunda matriz a restar.
 * @param c Matriz donde se almacenará el resultado de la resta.
 * @param K Índice de división de las matrices a y b.
 */
void substract(matrix& a, matrix& b, matrix& c, int K) {
    for ( int i = 0; i < K; i++) {
        for ( int j = 0; j < K; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}


/**
 * @brief Multiplica dos matrices cuadradas de tamaño n x n utilizando el algoritmo de Strassen.
 * 
 * Este algoritmo divide recursivamente las matrices de entrada en submatrices más pequeñas.
 * 
 * @param A Primera matriz a multiplicar.
 * @param B Segunda matriz a multiplicar.
 * @return matrix Matriz resultante de la multiplicación de a y b.
 */
matrix strassen(matrix& A, matrix& B ) {
    int N = A.size();
    int K = N/2;
    if ( N <= 2) {
        return matrix_mult(A,B);
    }

    matrix a(K,vector<int>(K,0)), b(K,vector<int>(K,0)), c(K,vector<int>(K,0)), d(K,vector<int>(K,0));
    matrix e(K,vector<int>(K,0)), f(K,vector<int>(K,0)), g(K,vector<int>(K,0)), h(K,vector<int>(K,0));

    matrix C1(K,vector<int>(K,0)), C2(K,vector<int>(K,0)), C3(K,vector<int>(K,0)), C4(K,vector<int>(K,0)), t1(K,vector<int>(K,0)), t2(K,vector<int>(K,0));

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + K];
            c[i][j] = A[i + K][j];
            d[i][j] = A[i + K][j + K];

            e[i][j] = B[i][j];
            f[i][j] = B[i][j + K];
            g[i][j] = B[i + K][j];
            h[i][j] = B[i + K][j + K];
        }
    }


    // P1 = (a + d)(e + h)
    add(a, d, t1, K); // t1 = a + d
    add(e, h, t2, K); // t2 = e + h
    matrix P1 = strassen(t1, t2); // P1 = (a + d)(e + h)

    // P2 = d(g-e)
    substract(g, e, t1, K); // t1 = g - e
    matrix P2 = strassen(d, t1); // P2 = d(g - e)

    // P3 = (a+b)h
    add(a, b, t1, K); // t1 = a + b
    matrix P3 = strassen(t1, h); // P3 = (a + b)h

    // P4 = (b-d)(g+h)
    substract(b, d, t1, K); // t1 = b - d
    add(g, h, t2, K); // t2 = g + h
    matrix P4 = strassen(t1, t2); // P4 = (b - d)(g + h)

    // P5 = a(f-h)
    substract(f, h, t1, K); // t1 = f - h
    matrix P5 = strassen(a, t1); // P5 = a(f - h)

    // P6 = (c+d)e
    add(c, d, t1, K); // t1 = c + d
    matrix P6 = strassen(t1, e); // P6 = (c + d)e

    // P7 = (a-c)(e+f)
    substract(a, c, t1, K); // t1 = a - c
    add(e, f, t2, K); // t2 = e + f
    matrix P7 = strassen(t1, t2); // P7 = (a - c)(e + f)

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            C1[i][j] = P1[i][j] + P2[i][j] - P3[i][j] + P4[i][j];
            C2[i][j] = P5[i][j] + P3[i][j];
            C3[i][j] = P6[i][j] + P2[i][j];
            C4[i][j] = P5[i][j] + P1[i][j] - P6[i][j] - P7[i][j];
        }
    }

    matrix result(N,vector<int>(N,0));
    for ( int i = 0; i < K; i++) {
        for ( int j = 0; j < K; j++) {
            result[i][j] = C1[i][j];
            result[i][j + K] = C2[i][j];
            result[i + K][j] = C3[i][j];
            result[i + K][j + K] = C4[i][j];
        }
    }
    return result;
}


#endif // STRASSEN_CPP