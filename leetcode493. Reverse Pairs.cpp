/* leetcode493. Reverse Pairs
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
 */
class Solution {
public:
    int mergesort(vector<int>& nums, int lo, int hi) {
        if (lo + 1 == hi) return 0;
        int mid = (lo + hi) / 2;
        int max = mergesort(nums, lo, mid) + mergesort(nums, mid, hi);

        for (int i = lo, j = mid; i < mid; i++) {
            while (j < hi && nums[i] > 2L*nums[j]) j++;
            max += j - mid;
        }
        int i = lo;
        int j = mid;
        vector<int> vformerge;
        while (i<mid || j<hi) {
            if (i >= mid || (j<hi&&nums[i] > nums[j])) {
                vformerge.push_back(nums[j]);
                ++j;
            }
            else {
                vformerge.push_back(nums[i]);
                ++i;
            }
        }
        for (int i = lo; i<hi; ++i) {
            nums[i] = vformerge[i - lo];
        }
        return max;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size()<2) return 0;
        return mergesort(nums, 0, nums.size());
    }
};