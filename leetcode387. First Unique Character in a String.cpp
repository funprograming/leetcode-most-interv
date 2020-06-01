/* leetcode387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto &c : s) {
            m[c]++;
        }
        //for (int i = 0; i < s.size(); i++) {
        //    if (m[s[i]] == 1) return i;
        //}
		for(auto iter = m.begin(); iter != m.end(); iter++) {
			if (iter->second == 1) return iter->second;
		}
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
		for (int i = 0; i<s.size(); ++i) {
			if (m.find(s[i]) == m.end())
				m[s[i]] = i;
			else m[s[i]] = -1;
		}
		for (int i = 0; i < s.size(); i++) {
		    if (m[s[i]] > -1) return i;
		}
        return -1;
    }
};