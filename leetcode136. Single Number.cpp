/* leetcode136. Single Number
Given a non-empty array of integers, every element appears twice except for one. 
Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto elem:nums)  m[elem]++;
        for(auto elem:m) if(elem.second==1) return elem.first;
        
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto elem:nums){
            result ^= elem;
        }
        return result;
    }
};