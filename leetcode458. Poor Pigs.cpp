/* leetcode458. Poor Pigs
There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. 
They all look the same. If a pig drinks that poison it will die within 15 minutes. 
What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) 
you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
 */

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int num=0;
        int matrix = 1;
		
		// 一头猪可以检测的桶数
		int x = minutesToTest/minutesToDie+1;
		// 按numapigtest进制对桶进行编码，编码完毕即可得到需要的猪数量
		// 如25桶 00 01 02 03 04 10 11 12 13 14...44
		// T1:让猪1检测bit0为0的桶,  让猪2检测bit1为0的桶...
		// T2:让猪1检测bit0为1的桶,  让猪2检测bit1为1的桶...
		// Tx:让猪1检测bit0为x-1的桶,让猪2检测bit1为x-1的桶...
		// 通过获取所有死亡猪的bit位即可得到桶的编码
        while(matrix < buckets){
            matrix *= x;     
            num++;
        }
        return num;
    }
};