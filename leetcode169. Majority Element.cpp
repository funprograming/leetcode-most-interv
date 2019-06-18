/* leetcode169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
//Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int count=0;
        for(int& elem : nums){
            if(count==0){
                majority = elem;
                count =1;
            }else{
                if(majority==elem) count++;
                else count--;
            }
        }
        return majority;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
// Since the majority element appears more than n / 2 times, 
// the n / 2-th element in the sorted nums must be the majority element. 
// In this case, a partial sort by nth_element is enough.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};