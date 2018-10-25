/* leetcode268. Missing Number.
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

//way 1 XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rst = nums.size();
        for(int i=0;i<nums.size();++i){
            rst = rst^i^nums[i];
        }
        return rst;
    }
};

//way 1 SUM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size()*(1+nums.size())/2;
        for(int i=0;i<nums.size();++i){
            sum -= nums[i];
        }
        return sum;
    }
};

//way 3 Binary Search
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size();
        while(i<j){
            int mid = (j+i)/2;
            if(mid>=nums[mid]){
                i = mid+1;
            }else{
                j = mid;
            }
        }
        return i;
    }
};