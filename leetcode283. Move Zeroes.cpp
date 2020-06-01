/* leetcode283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != 0 && nums[j] == 0) {
				swap(nums[i],nums[j++]);
                //nums[j++] = nums[i];
            }
            if(nums[j]!=0)
                j++;
        }
        //for (;j < nums.size(); j++) {
        //    nums[j] = 0;
        //}
    }
};