/* leetcode400. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */
class Solution {
public:
	int findNthDigit(int n) {
		int numberofdigits = 1;
		long base = 9;
		while (n - base * numberofdigits > 0)
		{
			n -= base * numberofdigits;
			base *= 10;
			numberofdigits++;
		}
		// 整数的序号
		int i = n / numberofdigits + (0 != (n%numberofdigits));
		// 对应的整数
		int integer = pow(10, numberofdigits-1) + i -1;
		// 对应整数的第j位
		int j = n%numberofdigits;        
		if (j == 0)
			j = numberofdigits;
		// 找出出该位
		for (int l= j; l < numberofdigits;++l) {
			integer /= 10;
		}
		return integer % 10;
	}
};