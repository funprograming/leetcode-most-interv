/* lleetcode046 Permutations
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
// way 1
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> vvi;
		vector<int> vi;
		backtrack(vvi, vi, nums);
		return vvi;
	}
	bool __find(vector<int> &vi, int i) {
		for (auto e : vi) {
			if (e == i) return true;
		}
		return false;
	}
	void backtrack(vector<vector<int>> &vvi, vector<int> &vi, vector<int>& nums) {
		if (vi.size() == nums.size()) {
			vvi.push_back(vi);
			return;
		}
		for (auto e : nums) {
			if (__find(vi, e)) continue;
			vi.push_back(e);
			backtrack(vvi, vi, nums);
			vi.pop_back();
		}
	}
};

// way 2
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};