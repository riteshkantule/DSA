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

// Better Approach
// Approach: Best (Binary Search)
// Finding the Kth Smallest Fraction with Spider-Man

// Introduction: Hey there, true believers! Your friendly neighborhood Spider-Man here to break down this mind-bending problem for you!

// Understanding the Problem: First things first, we gotta understand the problem itself. We've got an array of prime numbers, and we need to find the kth smallest fraction formed by dividing any two numbers in the array.

// Binary Search Trick: Now, we could go the brute-force way and calculate all the fractions, sort 'em, and pick the kth one. But that's just too easy, and Spider-Man never takes the easy way out!

// Binary Search Basics:

// a. We start with a range of possible values, from 0 to 1 in this case.

// b. We pick a value in the middle of the range, let's call it "mid."

// c. Then, we count how many fractions are less than or equal to "mid."

// d. If the count is equal to k, we've found our kth smallest fraction! Woohoo!

// e. If the count is less than k, we need to search for a larger fraction, so we update the lower bound of our range to "mid."

// f. If the count is greater than k, we need to search for a smaller fraction, so we update the upper bound of our range to "mid."

// g. We keep repeating this process until we find the kth smallest fraction.

// Counting Fractions: But wait, how do we count the number of fractions less than or equal to a given value? Well, that's where the real magic happens!

// Spider-Man's Strategy: For each number in the array, we find the smallest index "j" such that the fraction formed by dividing the current number by arr[j] is greater than "mid."

// Determining Fraction's Position: All the fractions formed by dividing the current number by arr[j] or any larger number in the array will be greater than "mid."

// Updating Count: So, we can add the count of all these fractions to our total count!

// Tracking Maximum Fraction: And while we're at it, we might as well keep track of the maximum fraction we've seen so far that's less than or equal to "mid." That way, we can return it if the total count ever equals k!

// Conclusion: Alright, true believers, that's the gist of it! With this approach, we can find the kth smallest fraction in O(n log n) time, which is way better than the brute-force approach.

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                
                total += n - j;

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return res;
    }
};
