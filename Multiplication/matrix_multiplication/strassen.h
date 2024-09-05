#ifndef STRASSEN_CPP
#define STRASSEN_CPP

/* 
Este algoritmo de Strassen asume que las matrices de entrada son cuadradas
y que sus dimensiones son de la forma n x n. Esto evita problemas con la recursión 
y garantiza que las matrices se puedan dividir en submatrices más pequeñas de igual tamaño.
*/


#include <bits/stdc++.h>

#define matrix vector<vector<int>>

using namespace std;

/**
 * @brief Suma dos matrices cuadradas de tamaño split_index y almacena el resultado en una tercera matriz.
 * 
 * @param a Primera matriz a sumar.
 * @param b Segunda matriz a sumar.
 * @param c Matriz donde se almacenará el resultado de la suma.
 * @param split_index Índice de división de las matrices a y b.
 */
void add_matrix(matrix& a, matrix& b, matrix& c, int split_index) {
    for ( int i = 0; i  < split_index; i++) {
        for ( int j = 0; j < split_index; j++) {
            c[i][j] = a[i][j] + b[i][j]; //Suma de los elementos correspondientes
        }
    }
    
}   

/**
 * @brief Multiplica dos matrices cuadradas de tamaño n x n utilizando el algoritmo de Strassen.
 * 
 * Este algoritmo divide recursivamente las matrices de entrada en submatrices más pqeueñas,
 * y combina los resultados parciales usando la técnica de Strassen.
 * 
 * @param m1 Primera matriz a multiplicar.
 * @param m2 Segunda matriz a multiplicar.
 * @return matrix Matriz resultante de la multiplicación de m1 y m2.
 */
matrix strassen_mult(matrix& m1, matrix& m2) {
    // Obtener las dimensiones de las matrices m1 y m2
    int col_1 = m1[0].size();
    int row_1 = m1.size();
    int col_2 = m2[0].size();
    int row_2 = m2.size();
    // Comprobar si las matrices pueden ser multiplicadas
    if (col_1 != row_2) {
        cout << "El numero de columnas de la matriz A debe ser igual al numero de filas de la matriz B \n";
        return {}; // Retorna una matriz vacía en caso de que no se puedan multiplicar
    }
    // Se crea la matriz de resultado de las dimensiones correspondientes (row_1 x col_2), inicializada en ceros
    matrix result_matrix( row_1, vector<int>(col_2,0));

    //Caso base: Cuando la matriz es 1x1, se multiplica directamente
    if ( col_1 == 1) result_matrix[0][0] = m1[0][0] * m2[0][0];
    else {

        //Dividir las matrices en submatrices más pequeñas
        //El índice de división será col_1/2, que es el tamaño de las submatrices (n/2 x n/2)
        int split_index = col_1 / 2; 
        // Inicializar las submatrices que resultarán de la multiplicación
        vector<int> row_vector(split_index,0); //Vector auxiliar para crear filas de ceros

        //Submatrices para la matriz de resultado
        matrix result_matrix_00(split_index,row_vector);
        matrix result_matrix_01(split_index,row_vector);
        matrix result_matrix_10(split_index,row_vector);
        matrix result_matrix_11(split_index,row_vector);

        // Submatrices de A (m1) y B (m2), que se utilizarán en las fórmulas de Strassen
        matrix a00(split_index,row_vector);
        matrix a01(split_index,row_vector);
        matrix a10(split_index,row_vector);
        matrix a11(split_index,row_vector);
        matrix b00(split_index,row_vector);
        matrix b01(split_index,row_vector);
        matrix b10(split_index,row_vector);
        matrix b11(split_index,row_vector);
        
        for ( int i = 0; i < split_index; i++) {
            for ( int j = 0; j < split_index; j++) {
                a00[i][j] = m1[i][j];
                a01[i][j] = m1[i][j + split_index];
                a10[i][j] = m1[split_index + i][j];
                a11[i][j] = m1[i + split_index][j + split_index];

                b00[i][j] = m2[i][j];
                b01[i][j] = m2[i][j + split_index];
                b10[i][j] = m2[split_index + i][j];
                b11[i][j] = m2[i + split_index][j + split_index];
            }
        }

        // Realizar las multiplicaciónes necesarias para strassen
        matrix c00_1 = strassen_mult(a00,b00);
        matrix c00_2 = strassen_mult(a01,b10);
        matrix c00_3 = strassen_mult(a00,b01);
        matrix c00_4 = strassen_mult(a01,b11);
        matrix c00_5 = strassen_mult(a10,b00);
        matrix c00_6 = strassen_mult(a11,b10);
        matrix c00_7 = strassen_mult(a10, b01);
        matrix c00_8 = strassen_mult(a11, b11);

        add_matrix( c00_1 , c00_2 , result_matrix_00 ,split_index);
        add_matrix( c00_3, c00_4 ,  result_matrix_01 , split_index);
        add_matrix( c00_5, c00_6, result_matrix_10, split_index);
        add_matrix(c00_7,c00_8,result_matrix_11,split_index);

        for ( int i = 0; i < split_index; i++) {
            for ( int j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j+split_index] = result_matrix_01[i][j];
                result_matrix[i+split_index][j] = result_matrix_10[i][j];
                result_matrix[i+split_index][j+split_index] = result_matrix_11[i][j];
            }
        }

    }
    return result_matrix;
}   

#endif // STRASSEN_CPP