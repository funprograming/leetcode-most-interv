/* leetcode028. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question 
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		GetNext(needle);
		int haystack_len = haystack.size();
		int needle_len = needle.size();
		int j = 0;
		int i = 0;

		while (j < haystack_len && i < needle_len) {
			if (i == -1 || haystack[j] == needle[i]) {
				i++;
				j++;
			}
			else {
				i = next_[i];
			}
		}
		if (i == needle_len) {
			return j - needle_len;
		}
		else return -1;
	}
	void GetNext(string needle) {
		int needle_len = needle.size();
		int i = -1;
		int j = 0;
		next_.push_back(-1);
		while (j < needle_len) {
			if (i == -1 || needle[i] == needle[j]) {
				i++;
				j++;
				next_.push_back(i);
			}
			else {
				i = next_[i];
			}
		}
	}
private:
	vector<int> next_;
};