#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
#include <vector>

using namespace std;

unordered_map<string, bool> mp;
vector<vector<int>> t;

bool ispalindrome(const string& str, int start, int end) {
    string key = to_string(start) + "-" + to_string(end);
    if (mp.count(key))
        return mp[key];

    while (start < end) {
        if (str[start] != str[end]) {
            mp[key] = false;
            return false;
        }
        start++;
        end--;
    }

    mp[key] = true;
    return true;
}

int solve(const string& str, int i, int j) {
    if (i >= j || ispalindrome(str, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k < j; k++) {
        if (t[i][k] == -1)
            t[i][k] = solve(str, i, k);
        if (t[k + 1][j] == -1)
            t[k + 1][j] = solve(str, k + 1, j);
        int temp = t[i][k] + t[k + 1][j] + 1;
        mn = min(temp, mn);
    }

    return t[i][j] = mn;
}

int main() {
    string str;
    cin >> str;

    int n = str.length();
    t.resize(n, vector<int>(n, -1));

    int result = solve(str, 0, n - 1);

    cout << result << endl;

    return 0;
}
