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
 * Este algoritmo divide recursivamente las matrices de entrada en submatrices más pequeñas,
 * 
 * @param X Primera matriz a multiplicar.
 * @param Y Segunda matriz a multiplicar.
 * @return matrix Matriz resultante de la multiplicación de a y b.
 */
matrix strassen(matrix& X, matrix& Y ) {
    int N = X.size();
    int K = N/2;
    if ( N <= 36) {
        return matrix_mult(X,Y);
    }

    matrix A(K,vector<int>(K,0)), B(K,vector<int>(K,0)), C(K,vector<int>(K,0)), D(K,vector<int>(K,0))
    , E(K,vector<int>(K,0)), F(K,vector<int>(K,0)), G(K,vector<int>(K,0)), H(K,vector<int>(K,0));

    matrix C1(K,vector<int>(K,0)), C2(K,vector<int>(K,0)), C3(K,vector<int>(K,0)), C4(K,vector<int>(K,0)), t1(K,vector<int>(K,0)), t2(K,vector<int>(K,0));

    for (int i = 0; i < K; i++) {
        for ( int j = 0; j < K; j++) {
            A[i][j] = X[i][j];
            B[i][j] = X[i][j + K];
            C[i][j] = X[i + K][j];
            D[i][j] = X[i + K][j + K];

            E[i][j] = Y[i][j];
            F[i][j] = Y[i][j + K];
            G[i][j] = Y[i + K][j];
            H[i][j] = Y[i + K][j + K];
        }
    }

    add(A,D,t1,K); //t1 = A + D
    add(E,H,t2,K); //t2 = E + H
    matrix P1 = strassen(t1,t2); //P1 = (A+D)(E+H)

    substract(G,E,t1,K); //t1 = G - E
    matrix P2 = strassen(A,t1); //P2 = A(G-E)

    add(A,B,t1,K); //t1 = A + B
    matrix P3 = strassen(H,t1); //P3 = H(A+B)

    substract(B,D,t1,K); //t1 = B - D
    add(G,H,t2,K); //t2 = G + H
    matrix P4 = strassen(t1,t2); //P4 = (B-D)(G+H)

    substract(F,H,t1,K); //t1 = F - H
    matrix P5 = strassen(A,t1); //P5 = A(F-H)

    add(C,D,t1,K); //t1 = C + D
    matrix P6 = strassen(t1,E); //P6 = (C+D)E

    substract(A,C,t1,K); //t1 = A - C
    add(E,F,t2,K); //t2 = E + F
    matrix P7 = strassen(t1,t2); //P7 = (A-C)(E+F)

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