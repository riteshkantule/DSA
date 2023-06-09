
#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector <int> wt, vector <int> val, int Weight, int n){
    
    if (n==0||Weight==0){
        return 0;
    }
    
    if (wt[n - 1] <= Weight) {
        int include = val[n - 1] + knapsack(wt, val, Weight - wt[n - 1], n - 1);
        int exclude = knapsack(wt, val, Weight, n - 1);
        return max(include, exclude);
    }
    else {
        return knapsack(wt, val, Weight, n-1);
    }
}



int main()
{
    vector <int> wt={1, 3, 5, 7};
    vector <int> val={2, 4, 9, 8};   // Initilize wt and val vectors
    int Weight=10;         // Initilize Weight
    int n = wt.size();
    
    int maxValue = knapsack(wt, val, Weight, n);
    cout << maxValue;

    return 0;
}
