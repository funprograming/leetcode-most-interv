/* leetcode053. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
// way 1 divide and conquer 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};

// way 2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsub = nums[0];
        for(int i=1;i<nums.size();++i){
            sum = max(sum+nums[i],nums[i]);
            maxsub = max(sum,maxsub);
        }
        return maxsub;
    }
};