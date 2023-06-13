// O(n^2) 0/1 Knapsack Memoization

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int Weight, int n, int t[102][1002]) {
    if (n == 0 || Weight == 0) {
        return 0;
    }
    if (t[n][Weight] != -1) {
        return t[n][Weight];
    }

    if (wt[n - 1] <= Weight) {
        int include = val[n - 1] + knapsack(wt, val, Weight - wt[n - 1], n - 1, t);
        int exclude = knapsack(wt, val, Weight, n - 1, t);
        return t[n][Weight] = max(include, exclude);
    } else {
        return t[n][Weight] = knapsack(wt, val, Weight, n - 1, t);
    }
}

int main(){
    
    vector <int> wt={1, 3, 5, 7};
    vector <int> val={2, 4, 9, 8};   // Initilize wt and val vectors
    int Weight=10;         // Initilize Weight
    int n = wt.size();
    
    int t[102][1002];          // initilize according to limit given in the question
    memset(t, -1, sizeof(t));  // here n<100 and w<1000 so we took extra space to be safe
    
    int maxValue = knapsack(wt, val, Weight, n, t);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
