/*
leetcode 1. Two Sum
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */
// Time complexity : O(n)O(n). We traverse the list containing nn elements exactly twice. 
// Since the hash table reduces the look up time to O(1)O(1), the time complexity is O(n)O(n).

// Space complexity : O(n)O(n). The extra space required depends on the number 
// of items stored in the hash table, which stores exactly nn elements. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];
            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);			
                return result;
            }

            //number was not found. Put it in the map.
            hash[nums[i]] = i;
        }
        return result;
    }
};