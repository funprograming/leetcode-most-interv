/* leetcode238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output 
such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array 
does not count as extra space for the purpose of space complexity analysis.)
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //time o(n), space o(1) 
        int n = nums.size();
        vector<int> rst;
        int tmp=1;
        for(int i=0;i<n;i++){
            if(i==0) rst.push_back(1);
            else{
                tmp *= nums[i-1];
                rst.push_back(tmp);
            } 
        }
        tmp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rst[i] *= tmp;
            tmp *= nums[i];
        }
        return rst;
    }
};