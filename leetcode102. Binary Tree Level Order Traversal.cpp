/* leetcode102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
// level
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> s;
        vector<int> level;
        queue<TreeNode*> nodes;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* n = s.front();
            s.pop();
            level.push_back(n->val);
            if(n->left)
                nodes.push(n->left);
            if(n->right)
                nodes.push(n->right);

            if(s.empty())
            {
                s.swap(nodes);
                result.push_back(level);
                level.clear();
            }
        }
        
        return result;
    }
};
// level 剑指offer
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> s;
        vector<int> level;
        s.push(root);
        int newlevel = 1;
        int nextlevel =0;
        while(!s.empty())
        {
            TreeNode* n = s.front();
            s.pop();
            level.push_back(n->val);
            if(n->left){
                s.push(n->left);
                nextlevel++;
            }
            if(n->right){
                s.push(n->right);
                nextlevel++;
            }
            newlevel--;
            if(newlevel==0)
            {
                newlevel = nextlevel;
                nextlevel = 0;
                result.push_back(level);
                level.clear();
            }
        }
        
        return result;
    }
};

//preorder
class Solution {
    vector<vector<int>> ret;
public:
    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());
        
        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildVector(root, 0);
        return ret;
    }
};