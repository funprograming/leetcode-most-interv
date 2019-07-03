/* leetcode5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};

//dp
class Solution {
public:
	string longestPalindrome(const string& s) {
		const int n = s.size();
		bool f[n][n];
		fill_n(&f[0][0], n * n, false);
		int maxLen = 1;
		int start = 0;
		for (int i = 0; i < n; ++i) {
			f[i][i] = true;
			for (int j = 0; j < i; ++j) {
				f[j][i] = (s[j] == s[i]) && (i - j < 2 || f[j + 1][i - 1]);
				if (f[j][i] && i - j + 1 > maxLen) {
					start = j;
					maxLen = i - j + 1;
				}
			}
		}
		return s.substr(start, maxLen);
	}
};