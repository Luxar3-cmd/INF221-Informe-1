#ifndef QUICK_SORT
#define QUICK_SORT

#include <bits/stdc++.h>
#include "algorithms.h"

using namespace std;

int partition(vector<int>& arr, int start, int end) {
    //Define pivote al final
    int pivot = arr[end];
    int i = start - 1;
    for ( int j = start ; j < end  ; j++ ){
        if( arr[j] < pivot ) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end]=temp;
    return i;
}

void QuickSort(vector<int>& arr, int start, int end){
    if ( start <= end) {
        int pivot = partition(arr, start, end);

        QuickSort(arr,start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }

}

#endif //QUICK_SORT