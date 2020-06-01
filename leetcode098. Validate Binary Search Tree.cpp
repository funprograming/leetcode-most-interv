/* leetcode98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> stack;
        TreeNode *pre = nullptr;
        while (true) {
            while (root != nullptr) {
             stack.push(root);
             root = root->left;
            }
			if(stack.empty()) break;
			root = stack.top();
			if(pre != nullptr && root->val <= pre->val) return false;
			stack.pop();
			pre = root;
			root = root->right;
        }
        return true;
    }
	/*
	if (root == nullptr) return true;
        stack<TreeNode*> stack;
        //TreeNode *pre = nullptr;
		long max_val = (long)INT_MIN-1;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
             stack.push(root);
             root = root->left;
            }
            root = stack.top();
            stack.pop();
			if(root->val<=max_val) return false;
			max_val = root->val;
            //if(pre != nullptr && root->val <= pre->val) return false;
            //pre = root;
            root = root->right;
        }
        return true;
    }
	*/

};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == nullptr) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != nullptr && prev->val >= node->val) return false;
        prev = node;
		if (!validate(node->right, prev)) return false;
        return true;
    }
};

class Solution {
	long max_val= (long)INT_MIN-1;
public:
    bool isValidBST(TreeNode* root) {
		if(!root) return true;
        if(!isValidBST(root->left))return false;
		if(root->val<=max_val) return false;
        max_val=root->val;
		if(!isValidBST(root->right))return false;
		return true;
    }
};