/* leetcode264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(1,1);
        int i=0,j=0,k=0;
        while(v.size()<n){
            v.push_back(min(v[i]*2,min(v[j]*3,v[k]*5)));
            if(v.back()==v[i]*2) ++i;
            if(v.back()==v[j]*3) ++j;
            if(v.back()==v[k]*5) ++k;
        }
        return v.back();

    }
};