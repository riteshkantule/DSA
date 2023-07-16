#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findMaximum(int arr[], int size) {
    int maximum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    return maximum;
}

int MAH(vector<int> c) {
    vector<int> left;
    stack<pair<int, int>> s;
    int pseudoindex = -1;

    int n = c.size();

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            left.push_back(pseudoindex);
        } else if (!s.empty() && s.top().first < c[i]) {
            left.push_back(s.top().second);
        } else if (!s.empty() && s.top().first >= c[i]) {
            while (!s.empty() && s.top().first >= c[i]) {
                s.pop();
            }
            if (s.empty())
                left.push_back(pseudoindex);
            else
                left.push_back(s.top().second);
        }
        s.push(make_pair(c[i], i));
    }

    vector<int> right;
    stack<pair<int, int>> s1;
    int pseudoindex1 = n;

    for (int i = n - 1; i >= 0; i--) {
        if (s1.empty()) {
            right.push_back(pseudoindex1);
        } else if (!s1.empty() && s1.top().first < c[i]) {
            right.push_back(s1.top().second);
        } else if (!s1.empty() && s1.top().first >= c[i]) {
            while (!s1.empty() && s1.top().first >= c[i]) {
                s1.pop();
            }
            if (s1.empty())
                right.push_back(pseudoindex1);
            else
                right.push_back(s1.top().second);
        }
        s1.push(make_pair(c[i], i));
    }

    reverse(right.begin(), right.end());

    int width[n];
    int area[n];
    for (int l = 0; l < n; l++) {
        width[l] = right[l] - left[l] - 1;
    }
    for (int j = 0; j < n; j++) {
        area[j] = width[j] * c[j];
    }
    return findMaximum(area, n);
}

int main() {
    int arr[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int n = 4;

    int max = 0;

    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(arr[i][j]);
        }

        if (i > 0) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    v[j] = 0;
                } else {
                    v[j] = v[j] + arr[i][j];
                }
            }
        }

        int max_MAH[2] = {max, MAH(v)};
        max = findMaximum(max_MAH, 2);
    }

    cout << max << endl;
    
return 0;
}
