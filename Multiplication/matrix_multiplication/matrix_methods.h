#ifndef MATRIX_METHODS
#define MATRIX_METHODS

#include <bits/stdc++.h>
#define matrix vector<vector<int>>

using namespace std;

//Esta función hace print de las matrices, de cualquier tamaño
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

//Función que lee el contenido del dataset y los guarda en una matriz de vectores.
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