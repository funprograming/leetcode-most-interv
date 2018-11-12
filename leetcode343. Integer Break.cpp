/* leetcode343. Integer Break
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
 */

// dp
class Solution {
public:
    int integerBreak(int n) {
        if(n==1 || n==2) return 1;
        else if(n==3) return 2;
        
        vector<int> product(n+1);
        product[1]=1;
        product[2]=2;
        product[3]=3;
        
        for(int i=4;i<=n;++i){
            int max=0;
            for(int j=1;j<=i/2;++j){
                int p = product[j]*product[i-j];
                if(max<p)
                    max = p;
                product[i] = max;    
            }
        }
        return product[n];
    }
};
// Greedy
class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3)
            return n-1;
        int res = 1;
        while(n>4){
            n = n-3;res = res*3;
        }
        return n*res;
    }
};