
#include <iostream>
#include <vector>
using namespace std;
 
int findMaximum(const vector<int>& testCase) {
    int maximum = 0;
    for (int i = 0; i < testCase.size(); i++) {
        maximum = max(maximum, testCase[i]);
    }
    return maximum;
}
 
vector<int> countRobots(const vector<int>& testCase) {
    vector<int> counts(101, 0);
    for (int i = 0; i < testCase.size(); i++) {
        counts[testCase[i]]++;
    }
    return counts;
}
 
bool isValidArrangement(const vector<int>& counts) {
    for (int i = 1; i < counts.size(); i++) {
        if (counts[i - 1] < counts[i]) {
            return false;
        }
    }
    return true;
}
 
void checkRobotArrangement(const vector<vector<int>>& testCases) {
    for (const vector<int>& testCase : testCases) {
        vector<int> counts = countRobots(testCase);
 
        if (isValidArrangement(counts)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
 
int main() {
    int t;
    cin >> t;
 
    vector<vector<int>> testCases;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> testCase(n);
 
        for (int i = 0; i < n; i++) {
            cin >> testCase[i];
        }
 
        testCases.push_back(testCase);
    }
 
    checkRobotArrangement(testCases);
 
    return 0;
}
