/* leetcode350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that 
you cannot load all elements into the memory at once?
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
// vector<int> intersect(vector<int>& a, vector<int>& b) {
//     unordered_map<int, int> ctr;
//     for (int i : a)
//         ctr[i]++;
//     vector<int> out;
//     for (int i : b)
//         if (ctr[i]-- > 0)
//             out.push_back(i);
//     return out;
// }
};