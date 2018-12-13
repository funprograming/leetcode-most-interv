/* leetcode171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
 */

class Solution {
public:
    int titleToNumber(string s) {
        int index = 0;
        int ret = 0;
        int power =1;
        while(index<s.size()){
            ret += power*(1 + s[s.size()-index-1] - 'A');
            power *= 26;
            ++index;
        }
        return ret;
    }
};