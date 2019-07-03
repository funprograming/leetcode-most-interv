/* leetcode349. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 */

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
		for (int a : nums1) {
			++m[a];
		}
		vector<int> res;
		for (int a : nums2){
            if (--m[a]>=0) {
				res.push_back(a);
			}
        }

		return res;
	}
};