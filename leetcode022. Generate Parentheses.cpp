/* leetcode022. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string s;
        backtrack(vs,s,0,0,n);
        return vs;
    }
    void backtrack( vector<string> &vs,string s,int open,int close,int n){
        if(s.size() == 2 * n) {
            vs.push_back(s);
            return;
        }
        if(open<n){
            backtrack(vs,s+"(",open+1,close,n);
        }
        if(close<open){
            backtrack(vs,s+")",open,close+1,n);
        }
    }
};