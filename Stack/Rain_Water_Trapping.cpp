#include <bits/stdc++.h>

using namespace std;


int sum_of_arr (const int arr[], int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum;
}


int main() {
    
    int arr[6] = {3, 0, 0, 2, 0, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxl[size];
    int maxr[size];
    int water[size];
    maxl[0]=arr[0];

    for (int i = 0; i < size; i++){
        maxl[i] = max(maxl[i-1], arr[i]);
    }
    for (int i = size; i >= 0; i--){
        maxr[i] = max(maxr[i+1], arr[i]);
    }
    for (int i = 0; i < size; i++){
        water[i]= min(maxl[i], maxr[i]) - arr[i];
    }
    
    cout << sum_of_arr(water, size) << endl;
    
return 0;
}
