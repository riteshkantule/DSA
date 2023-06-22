#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int LCS(string x, string y) {
    int n = x.size();
    int m = y.size();

    // Create a 2D array to store the lengths of LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Compute the lengths of LCS for all subproblems
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // The length of the LCS is stored in dp[n][m]
    return dp[n][m];
}

int main() {
    string x = "abcdih";
    string y = "abedlhr";

    cout << LCS(x, y) << endl;

    return 0;
}
