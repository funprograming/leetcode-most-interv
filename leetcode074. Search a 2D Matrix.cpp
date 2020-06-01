/* leetcode074. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
 */
// way 1 divide and conquer
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {		
        if(matrix.empty()){
            return false;
        }
        int r = matrix.size()-1;
        int c = 0;
        while(r>=0 && c<matrix[0].size()){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                r--;
            }
            else{
                c++;
            }
        }
        return false;
    }
};
// way 2 bs
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n;
        while(start <= end){
            int mid = start + (end - start)/2;
            int e = matrix[mid/n][mid%n];
            if(target < e){
                end = mid - 1;
            }
            else if(target > e){
                start = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};