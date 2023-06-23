#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int t[1001][1001];

int LCS(string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (t[n][m] != -1) {
        return t[n][m];
    }

    if (x[n - 1] == y[m - 1]) {
        t[n][m] = 1 + t[n-1][m-1];
    } else {
        t[n][m] = max(t[n][m-1], t[n-1][m]);
    }

    return t[n][m];
}

int main() {
    string x = "abcdih";
    string y = "abedlhr";

    int n = x.size();
    int m = y.size();

    memset(t, -1, sizeof(t));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    cout << LCS(x, y, n, m) << endl;

    return 0;
}
