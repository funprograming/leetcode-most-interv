/* leetcode230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often 
and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// way1
class Solution {
public:
    void helper(TreeNode *root, int k) {
        if (!root) return;
        if(!ret) helper(root->left,k);
        if (++count == k) {
            ret = root;
            return;
        }
        if(!ret) helper(root->right,k);
    }
    
    int kthSmallest(TreeNode *root, int k) {
        helper(root,k);
        return ret->val;
    }
private:
    int count=0;
    TreeNode *ret=nullptr;
};

// way2
class Solution {
public:
    TreeNode * helper(TreeNode *root, int &k) {
        TreeNode *ret=nullptr;
        if (!root) return nullptr;
        ret = helper(root->left,k);
        if(!ret){ // 避免找到结果后k仍--
            if (--k == 0) {
                ret = root;
            }
        }
        // 避免多余遍历
        if(!ret) ret = helper(root->right,k);
        return ret;
    }
    
    int kthSmallest(TreeNode *root, int k) {
        return helper(root,k)->val;
    }
};

//iterative
class Solution {
public:
    void walkleft(TreeNode *root, stack<TreeNode*> &s) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode*> s;
        while(root || !s.empty()){
            walkleft(root,s);
            root = s.top();
            if (--k == 0) {
                return root->val;
            }
            s.pop(); 
            root = root->right;
        }
    }
};