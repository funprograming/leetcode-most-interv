/* leetcode179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer. */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto i : nums)
            arr.push_back(std::to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2) { return s1 + s2>s2 + s1; });
        string res;
        for (auto s : arr)
            res += s;
        while (res[0] == '0' && res.length()>1)
            res.erase(0, 1);
        return  res;
    }
};