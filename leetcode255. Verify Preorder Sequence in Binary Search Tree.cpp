/* leetcode 255.Verify Preorder Sequence in Binary Search Tree
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (auto a : preorder) {
            if (a < low) return false;
            while (!s.empty() && a > s.top()) {
                low = s.top(); s.pop();
            }
            s.push(a);
        }
        return true;
    }
};

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return true;
        }
        return helper(preorder, 0, preorder.size() - 1);
    }
private:
    bool helper(vector<int> &preorder, int start, int end) {
        if (start >= end) {
            return true;
        }
        int root_val = preorder[start];
        int first_right = start + 1;
        while (first_right <= end && preorder[first_right] < root_val) {
            ++first_right;
        }
        for (int i = first_right; i <= end; ++i) {
            if (preorder[i] < root_val) {
                return false;
            }
        }
        bool left = helper(preorder, start + 1, first_right - 1);
        bool right = helper(preorder, first_right, end);
        return left && right;
    }
};
