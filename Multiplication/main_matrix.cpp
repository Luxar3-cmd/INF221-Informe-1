#include <bits/stdc++.h>
#include "matrix_methods.h"
#include "strassen.h"
#include "tmatrix_mult.h"


using namespace std;
#define matrix vector<vector<int>>

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