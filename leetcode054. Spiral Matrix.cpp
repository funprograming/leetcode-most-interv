/* leetcode54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(!matrix.size()) return v;
        int rowbegin=0;
        int columnsbegin=0;
        int rowend=matrix.size()-1;
        int columnsend=matrix[0].size()-1;
        int i;
        while(rowbegin<=rowend && columnsbegin<=columnsend){
            for(i=columnsbegin;i<=columnsend;++i){
                v.push_back(matrix[rowbegin][i]);
            }
            rowbegin++;
            for(i=rowbegin;i<=rowend;++i){
                v.push_back(matrix[i][columnsend]);
            }
            columnsend--;
            if(rowbegin<=rowend)
                for(i=columnsend;i>=columnsbegin;--i)
                    v.push_back(matrix[rowend][i]);
            
            rowend--;
            if(columnsbegin<=columnsend)
                for(i=rowend;i>=rowbegin;--i)
                    v.push_back(matrix[i][columnsbegin]);
            
            columnsbegin++;
        }
        return v;
    }
};