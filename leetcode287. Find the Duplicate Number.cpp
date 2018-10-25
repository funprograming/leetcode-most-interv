/* leetcode287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */

//way 1 修改原始数组 T:O(N) S:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            while(nums[i]!=i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                using std::swap;
                swap(nums[i],nums[nums[i]]);
            }
        }
    }
};

//way 2 二分查找，不修改原始数组 T:O(NlogN) S:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int mid;
        int high = nums.size()-1;
        int num=0;
        while(low<=high){
            num=0;
            mid = low+(high-low)/2;
            for(int i=0;i<nums.size();++i){
                if(nums[i]>=low && nums[i]<=mid){
                    num++;        
                }
            }
            if(num<=(mid-low+1)) low = mid+1;
            else high = mid;
            if(low==high) return low;        
        }
    }
};