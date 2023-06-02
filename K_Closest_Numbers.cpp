#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int, int>> maxH;

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x, k;
    cin >> x;
    cin >> k;
    for(int i = 0; i < n; i++) {
        maxH.push(make_pair(abs(arr[i] - x), arr[i]));
        if(maxH.size() > k) {
            maxH.pop();
        }
    }

    while(!maxH.empty()) {
        cout << maxH.top().second << " ";
        maxH.pop();
    }

return 0;
}
