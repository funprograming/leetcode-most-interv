/* leetcode033. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        // 找到最小点O(lgn)
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        //重置lo hi
        if(lo==0 || nums[0]>target){
            hi = nums.size()-1;
        }
        else{
            hi = hi-1;
            lo = 0;
        }
        
        //新的限定范围内二分查找
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] >= target) {
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        return nums[lo]==target? lo:-1;
        
    }
};
