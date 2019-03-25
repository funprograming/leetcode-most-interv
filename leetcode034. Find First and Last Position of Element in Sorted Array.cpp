/* leetcode34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int lo = 0;
        int hi = nums.size();
        int mid;
        vector<int> ret(2, -1);
        while(lo<hi){
            mid = (hi+lo)/2;
            if(nums[mid]>=target){
                hi = mid;
            }else{
                lo = mid+1;
            }
            mid = (hi+lo)/2;
        }
        if(lo>=nums.size() || nums[lo]!=target) return ret;
        else ret[0] = lo;
        hi = nums.size();
        while(lo<hi){
            mid = (hi+lo)/2;
            if(nums[mid]<=target){
                lo = mid+1;
            }else{
                hi = mid;
            }
            mid = (hi+lo)/2;
        }
        ret[1] = hi-1;

        return ret;
    }
};