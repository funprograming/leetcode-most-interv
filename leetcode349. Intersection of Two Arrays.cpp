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
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
		for (int a : nums1) {
			++m[a];
		}
		vector<int> res;
		for (int a : nums2){
            if (m[a]>0) {
				m.erase(a);
				res.push_back(a);
			}
        }

		return res;
	}
};
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> m(nums1.begin(), nums1.end());
		vector<int> res;
		for (auto a : nums2)
			if (m.count(a)) {
				res.push_back(a);
				m.erase(a);
			}
		return res;
	}
};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
		vector<int> res;
		for(auto e : s2){
			if(s1.count(e)>0)
				res.push_back(e);
		}
		return res;
	}
};