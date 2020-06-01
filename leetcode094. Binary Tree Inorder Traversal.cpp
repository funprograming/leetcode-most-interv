/* leetcode 94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
// way1 recursive
class Solution {
private:
    vector<int> v;
public:
    vector<int> inorderTraversal(TreeNode* root) {
		if(!root) return vector<int>();
		inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return v;
    }
};

// way1 iterative
class Solution {
private:
    vector<int> v;
    void golongleft(TreeNode* node,stack<TreeNode*> &s){
        while(node){
            s.push(node);
            node = node->left;
        }
    }
public:
/*
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while(true){
            golongleft(root,s);
            if(s.empty()) break;
            root = s.top();
            v.push_back(root->val);
            s.pop();
            root = root->right;
        }
        return v;
    }
	*/
	/*
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		while(true){
			golongleft(root,s);
			if(s.empty()) break;
			while(!s.empty()){			
				root = s.top();
				v.push_back(root->val);
				s.pop();
				root = root->right;
				if(root) break;
			}
		}
		return v;
	}
	*/
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		while(root){
			golongleft(root,s);
			//if(s.empty()) break;
			while(!s.empty()){			
				root = s.top();
				v.push_back(root->val);
				s.pop();
				root = root->right;
				if(root) break;
			}
		}
		return v;
	}
};
