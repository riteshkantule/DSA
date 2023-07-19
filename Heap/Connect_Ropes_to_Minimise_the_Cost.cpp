#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int n;
    cin >> n;

    int arr[n];

    priority_queue<int, vector<int>, greater<int>> minH;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        minH.push(arr[i]);
    }
    int cost=0;

    while (minH.size() > 1 ){
        int first = minH.top();
        minH.pop();
        int second = minH.top();
        minH.pop();
        cost = cost+first+second;
        minH.push(first+second);
    }.
        
    cout << cost << endl;

    return 0;
}
