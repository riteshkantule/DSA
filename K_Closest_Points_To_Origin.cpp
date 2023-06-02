#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[4][2]={{1,3},{-2,2},{5,8},{0,1}};

    int k;
    cin >> k;

    priority_queue <pair<int, pair<int, int>>> maxH;

    for (int i=0; i<4; i++){

        int distance = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
        pair<int, int> point = make_pair(arr[i][0], arr[i][1]);
        maxH.push(make_pair(distance, point));
        if (maxH.size()>k) maxH.pop();
    }

    while(maxH.size()!=0){
        pair <int , int> p = maxH.top().second;
        cout << p.first<< " "<<p.second<< endl;
        maxH.pop();
    }
    cout << endl;

return 0;
}