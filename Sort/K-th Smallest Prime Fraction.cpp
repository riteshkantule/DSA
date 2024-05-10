class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        auto cmp = [](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b) {
            return a.first < b.first;
        };
        vector<pair<double, pair<int, int>>> fractions;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double frac = (double)arr[i] / arr[j];
                fractions.push_back({frac, {arr[i], arr[j]}});
            }
        }
        sort(fractions.begin(), fractions.end(), cmp);
        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};
