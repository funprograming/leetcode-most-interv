/* leetcode437. Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

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
    int pathSumFromHead(TreeNode* root, int sum) {
        if(!root) return 0;
        return (root->val == sum ? 1 : 0)+\
                pathSumFromHead(root->left,sum-root->val)+pathSumFromHead(root->right,sum-root->val);
	}
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSumFromHead(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};

class Solution {
public:
    int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += help(root->left, sum, store, root->val) + help(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return help(root, sum, store, 0);
    }
};