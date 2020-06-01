/* leetcode236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
defined between two nodes p and q as the lowest node in T that has both p and q as 
descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself 
according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
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
    TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q){
        if( root == p || root == q || root == NULL)
            return root;
        TreeNode * parent1 = dfsTraverse(root->left, p, q);
        TreeNode * parent2 = dfsTraverse(root->right, p, q);
        //两个都有为root
        if( parent1 && parent2)
            return root;
        else
        //只有一个为自己
            return parent1 ? parent1:parent2;
    }
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q){
        return dfsTraverse(root, p, q);
    }
};

class Solution {
    public:
    void GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path1,list<TreeNode*>& path)
    {
        if(pRoot == NULL || pNode == NULL)
            return;
        path1.push_back(pRoot);
        if(pRoot == pNode){
			path = path1;
			path.push_back(nullptr);
		}
		GetNodePath(pRoot->left,pNode,path1,path);
		GetNodePath(pRoot->right,pNode,path1,path);
		path1.pop_back();
    }
    //求两个链表的最后一个公共节点
    TreeNode *GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
    {
        //从后往前找
        list<TreeNode*>::const_iterator it1 = path1.begin();
        list<TreeNode*>::const_iterator it2 = path2.begin();
		list<TreeNode*>::const_iterator ret = path1.begin();
		
        while(it1 != path1.end() && it2 != path2.end())
        {
            if(*it1 != *it2)
                return *ret;
			ret = it1;
			it1++;
			it2++;
        }
        return NULL;    
    }

	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q){
        list<TreeNode*> pathp,path1;
        GetNodePath(root,p,path1,pathp);
        list<TreeNode*> pathq,path2;
        GetNodePath(root,q,path2,pathq);

        return GetLastCommonNode(pathp,pathq);
    }
};