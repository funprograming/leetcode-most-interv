/* leetcode91. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6). 
*/
//ERR 递归存在重复项
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='\0') return 0;
        if(s.size()==1 && stoi(s.substr(0,2)) < 26) return 1;
        int sum = 0;
        sum += numDecodings(s.substr(1));
        sum += (stoi(s.substr(0,2)) < 26?1:0);
        sum += numDecodings(s.substr(2));
        return sum;
    }
};

//DP
class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();
		if (n == 0) return 0;

		vector<int> memo(n + 1, 0);
		memo[n] = 1;
		memo[n - 1] = s[n - 1] != '0' ? 1 : 0;

		for (int i = n - 2; i >= 0; i--)
			if (s[i] == '0') continue;
			else {
				int tmp = 10 * (s[i] - '0')+s[i + 1]- '0';
				memo[i] = tmp < 27 ? memo[i + 1] + memo[i + 2] : memo[i + 1];
			}

			return memo[0];
	}
};