
#include <bits/stdc++.h>
using namespace std;

int static t[101][101];

int solve(int e, int f){
    
    if (f==0||f==1){
        return f;
    }
    if (e==1){
        return f;
    }
    if (t[e][f]!=-1){
        return t[e][f];
    }
    
    int mn = INT_MAX;
    for (int k=1; k<= f; k++){
        int temp = 1 + max(solve(e-1, k-1),solve(e, f-k));
        
        mn = min(mn, temp);
    }
    return t[e][f] = mn;
}

int main()
{
    int e, f;
    cin >> e >> f;
    
    memset(t, -1, sizeof(t));
    cout << solve(e, f);

    return 0;
}
