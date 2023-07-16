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

int main()
{
    // NSL
    vector<int> left;
    stack<pair<int, int>> s;
    int psuedoindex = -1; // Changed from 0 to -1
    int c[] = {6, 2, 5, 4, 5, 1, 6};
    
    int n = sizeof(c) / sizeof(c[0]);

    for (int i = 0; i < n; i++) {
        if (s.empty()) { // Changed from s.size() == 0
            left.push_back(psuedoindex);
        } else if (!s.empty() && s.top().first < c[i]) {
            left.push_back(s.top().second);
        } else if (!s.empty() && s.top().first >= c[i]) {
            while (!s.empty() && s.top().first >= c[i]) { // Changed from s.size() > 0
                s.pop();
            }
            if (s.empty())
                left.push_back(psuedoindex);
            else
                left.push_back(s.top().second);
        }
        s.push(make_pair(c[i], i)); // Added make_pair to create a pair of value and index
    }
    // reverse (left.begin(), left.end());

    // NGR

    vector<int> right;
    stack<pair<int, int>> s1;
    int psuedoindex1 = n; // Changed from 7 to n
    
    for (int i = n-1; i >= 0; i--) { // Changed from i >= n to i >= 0
        if (s1.empty()) { // Changed from s1.size() == 0
            right.push_back(psuedoindex1);
        } else if (!s1.empty() && s1.top().first < c[i]) { // Changed from s1.size() > 0
            right.push_back(s1.top().second);
        } else if (!s1.empty() && s1.top().first >= c[i]) { // Changed from s1.size() > 0
            while (!s1.empty() && s1.top().first >= c[i]) { // Changed from s1.size() > 0
                s1.pop();
            }
            if (s1.empty())
                right.push_back(psuedoindex1);
            else
                right.push_back(s1.top().second);
        }
        s1.push(make_pair(c[i], i)); // Added make_pair to create a pair of value and index
    }
    
    reverse (right.begin(), right.end());


    int width[n];
    int area[n];
    for (int l = 0; l < n; l++) {
        width[l] = right[l] - left[l] - 1;
    }
    for (int j = 0; j < n; j++) {
        area[j] = width[j] * c[j];
    }
    // cout << endl;
    // for (int k = 0; k < n; k++) { // Changed k < n;ki++ to k < n
    //     cout << area[k] << " "; // Added a space after printing each area
    // }
    
    int max;
    
    cout << findMaximum(area, n);

    // cout << endl;

    return 0;
}
