#include <bits/stdc++.h>
#include "algorithms.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main () {
    ifstream data("Datasets_sorting/unordered_arr.txt");
    
    if (!data.is_open()) {
        cerr << "Error opening the data file" << endl;
        return 1;
    }

    int n = 10;

    vector<int> arr = read_arr(data, n);
    printVector(arr);
    vector<int> arr1 = arr; vector<int> arr2 = arr; vector<int> arr3 = arr;

    insertion_sort(arr1);
    printVector(arr1);

    merge_sort(arr2, 0, arr2.size()-1);
    printVector(arr2);

    QuickSort(arr3, 0, arr3.size()-1);
    printVector(arr3);



    return 0;

}