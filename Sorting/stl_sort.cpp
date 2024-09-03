#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {1,2,8,9,6,7,3,4,2,0};
    int n = arr.size();

    sort(arr.begin(), arr.begin() + n);

    cout << "Array after sorting using default sort is : \n";
    for ( int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

