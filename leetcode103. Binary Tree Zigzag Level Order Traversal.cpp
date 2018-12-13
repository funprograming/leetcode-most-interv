/* leetcode 103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if (root == NULL) {
//             return vector<vector<int> > ();
//         }
//         vector<vector<int> > vv;

//         queue<TreeNode*> q;
//         q.push(root);
//         int x=0;
//         while(!q.empty()){
//             int qsize = q.size();
//             vector<int> v;
//             for(int loop = 0; loop<qsize; ++qsize){
//                 // if(q.empty()) break;
//                 TreeNode* root =q.front();
//                 q.pop();
//                 v.push_back(root->val);
                
//                 if(x%2 ){
//                     if(root->left) q.push(root->left); 
//                     if(root->right) q.push(root->right);   
//                 }
//                 else{
//                     if(root->right) q.push(root->right);  
//                     if(root->left) q.push(root->left); 
//                 }
//             }
//             vv.push_back(v);
//             x++;
//         }
//         return vv;
//     }
// };

// 同102相似解法
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> s;
        vector<int> level(1);
        s.push(root);
        int newlevel = 1;
        int nextlevel =0;
        int zigzag = 0;
        int index = 0;
        while(!s.empty())
        {
            TreeNode* n = s.front();
            s.pop();

            newlevel--;
            if(zigzag==1){
                level[newlevel] =  n->val;
            }else{
                level[index++] =  n->val;
            }
            if(n->left){
                s.push(n->left);
                nextlevel++;
            }
            if(n->right){
                s.push(n->right);
                nextlevel++;
            }                
            
            if(newlevel==0)
            {
                zigzag = 1-zigzag;
                newlevel = nextlevel;
                
                result.push_back(level);
                level.resize(newlevel);
                nextlevel = 0;
                index =0;
                // level.clear();
            }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<int> > result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};