/* leetcode65. Valid Number
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */
class Solution {
public:
    bool isNumber(string s) {
        while(s[0]==' ')  s.erase(0,1);//delete the  prefix whitespace 
        while(s[s.length()-1]==' ') s.erase(s.length()-1, 1);//delete the suffix whitespace
        
        bool pointSeen = false;
        bool eSeen = false;
        bool numberSeen = false;
        bool numberAfterE = true;
        for(int i=0; i<s.length(); i++) {
            if('0' <= s[i]&& s[i]<= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if(s[i]== '.') {
                if(eSeen || pointSeen) {
                    return false;
                }
                pointSeen = true;
            } else if(s[i]== 'e') {
                if(eSeen || !numberSeen) {
                    return false;
                }
                numberAfterE = false;
                eSeen = true;
            } else if(s[i]== '-' || s[i]== '+') {
                if(i != 0 && s[i-1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        // At the and it is only valid if there was at least 1 number and if we did see an e then a number after it as well.
        return numberSeen && numberAfterE;
    }
};