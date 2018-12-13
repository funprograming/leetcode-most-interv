/* leetcode7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

// way 1
class Solution {
public:
	int reverse(int x) {
		vector<int> v;
		int i = 0;
		unsigned int ux;
		bool negtive = false;
		if (x<0) {
			x = x + 1;  //avoid -2^31
			x = -x;
			ux = x + 1; 
			negtive = true;
		}
		else ux = x;

		while (ux>0) {
			v.push_back(ux % 10);
			ux /= 10;
		}

		int j = 0;
		while (j<v.size()) {
			if (v[j] != 0) break;
			j++;
		}

		int y = 0;
		while (j<v.size()) {
			if (0x7fffffff - y < v[j]) return 0;
			y += v[j] * pow(10, v.size() - j - 1);
			j++;
		}
		return negtive ? -y : y;
	}
};

// way 2
class Solution {
public:
	int reverse(int x) {
        int result = 0;

        while (x != 0)
        {
            int tail = x % 10;
            int newResult = result * 10 + tail;
            if ((newResult - tail) / 10 != result){ 
                return 0; 
            }
            result = newResult;
            x = x / 10;
        }

        return result;
	}
};