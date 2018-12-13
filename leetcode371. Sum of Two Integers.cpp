/* leetcode371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
 */

class Solution {
public:
    int getSum(int a, int b) {
        int ret[32]={0};
        int interg = 0;
        int i=0;
        while(i<32){
            int t1 = (a>>i) & 1;
            int t2 = (b>>i) & 1;
            ret[i] = interg ^ (t1 ^ t2);
            interg = (t1 + t2 + interg) > 1;
            i++;
        }
        int sum=0;
        i=0;
        int t = 1;
        while(i<32){
            if(ret[i] != 0){
                sum += t;
            }
            t *= 2;
            i++;
        }
        return sum;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }

        return sum;
    }

};

class Solution {
public:
    int getSum(int a, int b) {
	    return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
};