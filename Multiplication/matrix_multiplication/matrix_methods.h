#ifndef MATRIX_METHODS
#define MATRIX_METHODS

#include <bits/stdc++.h>
#define matrix vector<vector<int>> // Definimos "matrix" como un alias de vector<vector<int>>

using namespace std;

/**
 * @brief Multiplica dos matrices de cualquier tamaño
 *
 * Esta función recibe una matriz de enteros como referencia y la 
 * imprime en consola. Si la matriz está vacía, imprime un mensaje 
 * indicando que no se puedo leer la matriz.
 * 
 * @param mat Matriz a imprimir, de tipo 'matrix' (alias de vector<vector<int>>)
 */
void print_matrix(const matrix& mat) {
    if (mat.empty()) {
        cout << "Matrix is empty or could not be read!" << endl;
        return;
    }

    for (const auto& row : mat) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Lee una mtriz desde un archivo de entrada.
 * 
 * Esta función toma un flujo de entrada (ifstream) que representa un archivo,
 * y lee dos enteros que indican el tamaño de la matriz (n y m). Luego, lee
 * los valores de la matriz del archivo y los guarda en una estructura vectorial.
 * 
 * Si el archivo no tiene más matrices para leer, retorna una matriz vacía.
 * 
 * @param data Referencia a un flujo de entrada (archivo) desde donde se leerán los datos.
 * @return matrix Retorna una matriz de tamaño n x m con los valores leídos.
 * 
 */
matrix read_matrixs(ifstream& data) {    
    string line; 
    int n, m, num;

    if(!(data >> n >> m)) {
        return matrix(); //Retorna una matriz vacía si no hay más matrices para leer
    }
    matrix trix(n, vector<int>(m,0));
    for ( int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data >> num;
            trix[i][j] = num;
            
        }
    }
    return trix;
}

#endif //MATRIX_METHODS