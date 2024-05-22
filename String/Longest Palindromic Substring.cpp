class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        if (l == 0) return "";

        string ans = "";

        for (int i = 0; i < l; i++) {
            string local_ans = expandAroundCenter(s, i, i);
            if (local_ans.length() > ans.length()) {
                ans = local_ans;
            }

            local_ans = expandAroundCenter(s, i, i + 1);
            if (local_ans.length() > ans.length()) {
                ans = local_ans;
            }
        }

        return ans;
    }

private:
    string expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
