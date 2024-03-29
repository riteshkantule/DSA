#include <bits/stdc++.h>
// This code is modified in solve function for optimization
using namespace std;

int static matrix[1001][1001];

bool ispalindrome(const string& str, int i, int j) {
    if (i == j) return true;
    if (i > j) return true;
    while (i < j) {
        if (str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(const string& str, int i, int j) {
    if (i >= j || ispalindrome(str, i, j))
        return 0;

    if (matrix[i][j] != -1)
        return matrix[i][j];

    int mn = INT_MAX;

    for (int k = i; k < j; k++) {
        if (matrix[i][k] == -1)
            matrix[i][k] = solve(str, i, k);
        if (matrix[k + 1][j] == -1)
            matrix[k + 1][j] = solve(str, k + 1, j);
        int temp = matrix[i][k] + matrix[k + 1][j] + 1;
        mn = min(temp, mn);
    }

    return matrix[i][j] = mn;
}

int main() {
    string str;
    cin >> str;

    memset(matrix, -1, sizeof(matrix));

    int n = str.length();

    int result = solve(str, 0, n - 1);

    cout << result << endl;

    return 0;
}
