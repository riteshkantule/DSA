#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        int count_minus_one = 0;
        int sum = 0;
        int product = 1;
 
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                count_minus_one++;
            }
            sum += a[i];
            product *= a[i];
        }
 
        int operations = 0;
        while (sum < 0 || product != 1) {
            sum += 2;
            product *= -1;
            operations++;
        }
 
        cout << operations << endl;
    }
 
    return 0;
}
