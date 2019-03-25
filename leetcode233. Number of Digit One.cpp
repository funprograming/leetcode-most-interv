/* leetcode233. Number of Digit One
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

class Solution {
public:
    int countDigitOne(int n) {
        if(n<1) return 0;
        if(n>=1 && n<10) return 1;
        // x: first digit
        int y=1, x=n;
        while(!(x<10)){
            x/=10;
            y*=10;
        }
        // countDigitOne(234) // 拆分为 0~34 + 35~234
        //= 最高位出现1的个数（35~234） // x==1 ? (n-y+1) : y
        // +后几位（35~234） // x*countDigitOne(y-1) //35~234个数等价0~99
        // + 0~34 // countDigitOne(n%y)
        return ( x==1 ? (n-y+1) : y) + x*countDigitOne(y-1) + countDigitOne(n%y);
    }
};