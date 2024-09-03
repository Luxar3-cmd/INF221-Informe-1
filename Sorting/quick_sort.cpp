#include <bits/stdc++.h>

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

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    vector<int> datos = {1,9,2,4,5,0,10};
    int n = datos.size();



    QuickSort(datos, 0, n-1);
    cout << "Sorted array: \n";
    printArray(datos);

    return 0;
}