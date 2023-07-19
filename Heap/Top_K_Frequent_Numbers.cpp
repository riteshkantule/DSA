#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;

    int arr[n];

    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    
    for(auto it = mp.begin(); it != mp.end(); it++) {
        minH.push(make_pair(it->second, it->first));
        if(minH.size() > k) {
            minH.pop();
        }
    }

    while(!minH.empty()) {
        cout << minH.top().second << " ";
        minH.pop();
    }

    return 0;
}
