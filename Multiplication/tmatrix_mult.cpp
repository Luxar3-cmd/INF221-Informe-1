#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

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

int main() {
    ifstream data("data.txt");

    if ( !data.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    
    while (true)
    {
        matrix m1 = read_matrixs(data);
        if (m1.empty()) break;

        matrix m2 = read_matrixs(data);
        if (m2.empty()) break;
        
        auto start = chrono::high_resolution_clock::now();

        matrix result = matrix_mult(m1,m2);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
        
        cout << duration.count() << " ms" << endl;

        cout << "Resultado: " << endl;
        print_matrix(result);
    }

    
    data.close();

    return 0;
}