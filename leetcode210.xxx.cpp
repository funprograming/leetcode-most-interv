/* leetcode217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
 */
// way 1 set Time complexity: O(N), memory: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(auto e:nums){
            if(us.count(e)==0){
                us.insert(e);
            }else{
                return true;
            }
        }
        if(nums.size()==us.size()){
            return false;
        }
    }
};
// way 2 set Time complexity: O(N), memory: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();     
    }
};