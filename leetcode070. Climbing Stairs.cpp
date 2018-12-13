/* leetcode70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 */

// F(1)=1 F(2)=2
// F(N) = F(N-1)+F(N-2)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int i = 1;
        int j = 2;
        int ret;
        int cnt=1;
        while(++cnt<n){
            ret = i+j;
            i = j;
            j = ret;
        }
        return ret;
    }
};