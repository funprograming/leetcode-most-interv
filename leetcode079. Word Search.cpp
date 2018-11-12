/* leetcode079. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */
class Solution {
    public:
    	 bool exist(vector<vector<char> > &board, string word) {
            m=board.size();
            n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
    				if(isFound(board,word,x,y,0))
    					return true;
                }
            return false;
        }
    private:
    	int m;
    	int n;
        
        bool isFound(vector<vector<char> > &board, string &word, int x, int y,int index)
        {
    		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||word[index]!=board[x][y])
    			return false;
            if(index==word.size()-1)
                return true;
    		char t=board[x][y];
    		board[x][y]='\0';
    		if(isFound(board,word,x-1,y,1+index)
               ||isFound(board,word,x+1,y,1+index)
               ||isFound(board,word,x,y-1,1+index)
               ||isFound(board,word,x,y+1,1+index))
    			return true; 
    		board[x][y]=t;
            return false;
        }
    };