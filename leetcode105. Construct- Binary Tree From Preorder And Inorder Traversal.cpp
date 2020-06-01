/* leetcode105. Construct- Binary Tree From Preorder And Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */
// way 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// way 1
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        // 可以就地处理
        vector<int> preorder_left,inorder_left;
        vector<int> preorder_right,inorder_right;
        int i = 0;
        while(inorder[i]!=preorder[0]){
            inorder_left.push_back(inorder[i]);
            preorder_left.push_back(preorder[i+1]);
            i++;
        }
        preorder_right.assign(preorder.begin()+i+1, preorder.end());
        inorder_right.assign(inorder.begin()+i+1, inorder.end());
        
        root->left  = buildTree(preorder_left,inorder_left);
        root->right = buildTree(preorder_right,inorder_right);
        return root;
    }
};
// way 2
public TreeNode buildTree(int[] preorder, int[] inorder) {
    return helper(0, 0, inorder.length - 1, preorder, inorder);
}

public TreeNode helper(int preStart, int inStart, int inEnd, int[] preorder, int[] inorder) {
    if (preStart > preorder.length - 1 || inStart > inEnd) {
        return null;
    }
    TreeNode root = new TreeNode(preorder[preStart]);
    int inIndex = 0; // Index of current root in inorder
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root.val) {
            inIndex = i;
        }
    }
    root.left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
    root.right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
    return root;
}