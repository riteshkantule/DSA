#include <iostream>
#include <cstring>
using namespace std;

int countSubsetsWithGivenDifference(int arr[], int n, int diff) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int subsetSum = (diff + totalSum) / 2;
    int dp[n + 1][subsetSum + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= subsetSum; j++) {
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][subsetSum];
}

int main(){
    
    int n, diff;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> diff;

    int count = countSubsetsWithGivenDifference(arr, n, diff);
    cout << count << endl;

    return 0;
}
