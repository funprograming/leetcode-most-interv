/* 50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1] 
*/

// way 1
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double t = myPow(x,n/2);
        if(0 != n%2) return n<0 ? 1/x*t*t : x*t*t;
        else return t*t;
    }
};

// way 2
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n = -n;
            x = 1/x;
            return 1/x*myPow(1/x, -(n+1)) // -(n+1)为了避免int越限
        }
        return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
};

// way 3