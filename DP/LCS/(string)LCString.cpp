#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string common_subsequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> t(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i)
        t[i][0] = 0;

    for (int j = 0; j <= m; ++j)
        t[0][j] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            } else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            ans.push_back(str1[i - 1]);
            i--;
            j--;
        } else {
            if (t[i - 1][j] > t[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    
    string result = common_subsequence(str1, str2);
    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}
