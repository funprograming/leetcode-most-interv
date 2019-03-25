/* leetcode053. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
// way 1 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();++i){
            // if(sum<0){
            //     sum=0;
            // }     
            // sum+=nums[i];
            sum = nums[i] + (sum > 0 ? sum : 0);
            if(sum>max){
                max = sum;
            }
        }
        return max;
    }
};

// way 2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsub = nums[0];
        for(int i=1;i<nums.size();++i){
            sum = nums[i] + (sum > 0 ? sum : 0);
            maxsub = max(sum,maxsub);
        }
        return maxsub;
    }
};