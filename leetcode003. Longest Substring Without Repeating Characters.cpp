/* leetcode3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
		int maxlen = 1;
		for(int i = n-1;i>=0;--i){
			maxlen = max(maxlen,helper(s,i));
		}
		return maxlen;
    }
	int helper(string s,int i){
		set<char> strs;
		while(i<s.size() && (strs.end() == strs.find(s[i]))){
			strs.insert(s[i]);
			++i;
		}
		return strs.size();
	}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        
        int i,start=-1,ans=0;
        for(i=0;i<s.size();i++){
			// tips:>0 在元素第3次出现时判断出错abcabcbb
			//if(v[s[i]]>0){
			// 表示前边出现重复元素的位置比start更近，必须更新start
            if(v[s[i]]>start){
                start = v[s[i]];
            }
            v[s[i]] = i;
            ans = max(ans,i-start);
        }
        return ans;
    }
};