/* leetcode151. Reverse Words in a String
Given an input string, reverse the string word by word.

Example:  

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.
*/
class Solution {
public:
    void reverseString(string &s, int begin, int end) {
        int len = end - begin;
        for (int i = begin; i<begin + len / 2; i++) {
            swap(s[i], s[--end]);
        }
    }
void removeblank(string &s) {
	int i = 0; int j = 0; int len = s.size();
	int wordcount = 0;
	while (true) {
		while (i<len && s[i] == ' ') i++;  // skip spaces in front of the word
		if (i == len) break;
		if (wordcount) s[j++] = ' ';
		while (i<len && s[i] != ' ') { s[j] = s[i]; j++; i++; }
		wordcount++;
	}
	s.resize(j);
}

    void reverseWords(string &s) {
        removeblank(s);
        reverseString(s, 0, s.size());
        int i = 0;
        for (i = 0; i<s.size(); i++) {
            int j = i;
            while (i<s.size() && s[i] != ' ') {
                i++;
            }reverseString(s, j, i);
        }
    }
};