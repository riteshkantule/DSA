
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(long long x, vector<long long>& arr) {
    long long count = 1, maxm = arr[0], minm = arr[0];
    for (long long i = 1; i < arr.size(); i++) {
        maxm = arr[i];
        if (((maxm - minm + 1) / 2) > x) {
            count++;
            minm = arr[i];
        }
    }
    if (count > 3)
        return false;
    return true;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long v = 0;
        long long c = 0;
        for (long long t : a) {
            if (t <= q) {
                c++;
            } else {
                c = 0;
            }
            if (c >= k) {
                v += c - k + 1;
            }
        }
        cout << v << endl;
    }
    return 0;
}
