#include <iostream>
#include <vector>

using namespace std;

int findFirstMinimum(const vector<int>& arr, int i) {
    int minVal = arr[i];
    int minIdx = -1;
    
    for (int j = i+1; j < arr.size(); j++) {
        if (arr[j] <= arr[i]) {
            minIdx = j;
            break;
        }
    }
    
    return minIdx;
}



int main() {
    int n;
    cin >> n;
    
    int total_cost = 0;
    vector<int> prices(n);
    vector<int> full_prices;
    
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    for (int i = 0; i < n; i++) {
        int minIdx = findFirstMinimum(prices, i);
        if (minIdx != -1 && prices[i] >= prices[minIdx]) {
            total_cost += (prices[i] - prices[minIdx]);
        } else {
            total_cost += prices[i];
            full_prices.push_back(i);
        }
    }
    
    cout << total_cost << endl;
    
    for (int i = 0; i < full_prices.size(); i++) {
        cout << full_prices[i] << " ";
    }
    
    return 0;
}

