/* leetcode43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
class Solution {
public:
string multiply(string num1, string num2) {
    if(num1[0]=='0' || num2[0]=='0') return "0";
	int num1size = num1.size();
	int num2size = num2.size();
	vector<int> v(num1size + num2size, 0);

	for (int i = num1size - 1; i >= 0; i--) {
		for (int j = num2size - 1; j >= 0; j--) {
			int mul = (num1[i] - '0')*(num2[j] - '0');
			v[i + j] += mul / 10;
			if (v[i + j] >= 10) {
				v[i + j - 1] += 1;
				v[i + j] = v[i + j] % 10;
			}
			v[i + j + 1] += mul % 10;
			if (v[i + j + 1] >= 10) {
				v[i + j] += 1;
				v[i + j + 1] = v[i + j + 1] % 10;
			}
		}
	}
	int first = 0;
	while (v[first++] == 0) {
		;
	}
	string s = "";
	for (int i = first-1; i <= num1size+ num2size - 1; i++)
		s += (char)(v[i] + '0');
	//std::copy(v.begin()+i, v.end(), rst);
	return s;
}
};