#include <bits/stdc++.h>
#include "algorithms.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main ( ) {

    ifstream data("Datasets_sorting/unordered_arr.txt");

    if ( !data.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    vector<int> arr = read_arr(data);

    printVector(arr);

    return 0;
    
}