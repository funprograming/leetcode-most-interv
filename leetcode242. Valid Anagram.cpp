/* leetcode242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
		map<char,int> m;
		for (auto elm : s) {
            m[elm]++;
        }
		for (auto elm : t) {
            if (m[elm]>0)  m[elm]--;
            else return false;
		}
		return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());		
		std::sort(t.begin(), t.end());
		int i = 0, j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] != t[j]) break;
            i++;j++;
		}
		return j == t.size() && i == s.size();
    }
};