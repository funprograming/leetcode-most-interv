/* leetcode771. Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0*/

#include <unordered_set>
using std::unordered_set;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        unordered_set<char> J_set(J.begin(),J.end());
        for(char elem:S){
            if(J_set.count(elem)) count++;
        }
        return count;
    }
};

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        return std::count_if(std::begin(S),std::end(S),[&J](char c)
                      {
                          return J.find(c)!=std::string::npos;
                      });
    }
};