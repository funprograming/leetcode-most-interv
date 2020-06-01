/* leetcode231. Power of Two
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 2^0 = 1
Example 2:

Input: 16
Output: true
Explanation: 2^4 = 16
Example 3:

Input: 218
Output: false
 */

// way 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        long p = 1;
        while(p<n){
            p = p<<1;
            if(n == p) return true;
        }
        return false;
    }
};

// way 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }
};

// way 3
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n-1)) == 0);
    }
};

// way 4
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n==1 || (n%2==0 && isPowerOfTwo(n/2)));
    }
};