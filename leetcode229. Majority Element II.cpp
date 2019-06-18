/* leetcode229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        
        int count1=0, count2=0;
        int result1=INT_MAX, result2=INT_MAX;
        
        for(int num:nums){
            if(num==result1) count1++;
            else if(num==result2) count2++;
            else if(count1==0) { result1=num; count1=1; }
            else if(count2==0) { result2=num; count2=1; }
            else { count1--; count2--; }
        }
        
        count1=count2=0;
        for(int num:nums){
            if(num==result1) count1++;
            else if(num==result2)  count2++;
        }
        
        if(count1>n/3) result.push_back(result1);
        if(count2>n/3) result.push_back(result2);
        
        return result;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        int n = nums.size();
    // sort(nums.begin(), nums.end());
        nth_element(nums.begin(), nums.begin()+n/3, nums.end());
        nth_element(nums.begin(), nums.begin()+2*n/3, nums.end());
        int cand1 = nums[n/3], cand2 = nums[2*n/3];
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand1) cnt1++;
            else if (nums[i] == cand2) cnt2++;
        }
        vector<int> ans;
        if (cnt1 > n/3) ans.push_back(cand1);
        if (cnt2 > n/3) ans.push_back(cand2);
        return ans;
    }
};