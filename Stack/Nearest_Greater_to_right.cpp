#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    stack<int> s;

    int c[] = {1, 3, 2, 4};
    int n = sizeof(c) / sizeof(c[0]); // Calculate the size of array c

    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            v.push_back(-1);
        } else if (s.size() > 0 && s.top() > c[i]) {
            v.push_back(s.top());
        } else if (s.size() > 0 && s.top() <= c[i]) {
            while (s.size() > 0 && s.top() <= c[i]) {
                s.pop();
            }
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(c[i]);
    }

    // reverse(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
