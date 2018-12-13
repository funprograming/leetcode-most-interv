/* leetcode191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int flag = 1;
        while(flag){
           if(n & flag){
               count++;
           }
           flag = flag<<1; //当n可为有符号数的时候直接移n会有符号
        }
        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
           ++count;
           n &= n-1; 
        }
        return count;
    }
};