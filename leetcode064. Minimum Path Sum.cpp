/* leetcode64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
//space O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int r = grid.size();
		int c = grid[0].size();
        vector<vector<int>> vv(r,vector<int>(c,grid[0][0]));
		for(int i = 1;i<r;++i){
			vv[i][0] = vv[i-1][0] + grid[i][0]; 
		}
		for(int j = 1;j<c;++j){
			vv[0][j] = vv[0][j-1] + grid[0][j]; 
		}		

		for(int i = 1;i<r;++i){
			for(int j = 1;j<c;++j){
				vv[i][j] = min(vv[i-1][j],vv[i][j-1])+grid[i][j];
			}
		}
		return vv[r-1][c-1];
    }
};

//space O(n)
// 逐行计算，仅需保存计算行的信息即可
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int r = grid.size();
		int c = grid[0].size();
        vector<int> v(c,grid[0][0]);
		for(int i = 1;i<c;++i){
			v[i] = v[i-1] + grid[0][i]; 
		}		
		for(int i = 1;i<r;++i){
			v[0] += grid[i][0];
			for(int j = 1;j<c;++j){
				//     // 2 4 5
				// i==1// 6 7 6
				// i==2// 6 8 7
				v[j] = min(v[j],v[j-1])+grid[i][j];
			}
		}
		return v[c-1];
    }
};