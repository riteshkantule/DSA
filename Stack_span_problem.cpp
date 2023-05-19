#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    stack<pair<int, int>> s;

    int c[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(c) / sizeof(c[0]); // Calculate the size of array c

    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            v.push_back(-1);
        } else if (s.size() > 0 && s.top().first > c[i]) { //change is just "".first"
            v.push_back(s.top().second);
        } else if (s.size() > 0 && s.top().first <= c[i]) { //change is just "".first"
            while (s.size() > 0 && s.top().first <= c[i]) { //change is just "".first"
                s.pop();
            }
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push(make_pair(c[i], i));
    }

    reverse(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
