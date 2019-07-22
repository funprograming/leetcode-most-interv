/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include <cstdio>
#include <math.h>

// P(n个骰子掷出k)=1/6*[P(n-1个骰子掷出k-1)+p(n-1个骰子掷出k-2)+....+p(n-1个骰子掷出k-6)]
// 由此可知p(n,k)=1/6*(p(n-1,k-1)+p(n-1,k-2)+....+p(n-1,k-6))
class Solution 
{
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) 
	{
        // Write your code here
        vector<pair<int, double>> results;
        double f[n + 1][6 * n + 1];
        memset(f, 0, sizeof(f));
 
        for (int i = 1; i <= 6; ++i) 
            f[1][i] = 1.0 / 6;
        
        for (int i = 2; i <= n; ++i) // 第 i 个骰子的点数和情况，其情况由前 (i-1) 个 骰子的点数和推出 
            for (int j = i; j <= 6 * i; ++j){ // i 个骰子的点数和范围，必定为 [i, 6i]，全为1和全为6时，分别取得上下界 
                for (int k = 1; k <= 6; ++k) // 第 n 个骰子的点数只可能为 1到6 
                    if (j > k) // j-k 必须严格大于0 (因为在这题中，由于i和j的实际意义分别为，投掷次数，和点数总和，所以两者的最小值都不可能取到0) 
                        f[i][j] += f[i - 1][j - k]; //相应的，前(n-1)个骰子的点数和，就是 j-k，累加是为枚举所有能凑出 点数和为 j 的情况，并将出现概率求和 
                f[i][j] /= 6.0; // 在没有除以6之前，表示的是在最后一次掷出k点的情况下，n 次投掷得到的点数和为 j 的概率 
            }
 
        for (int i = n; i <= 6 * n; ++i) //n个骰子点数和范围必为[n,6n]，只要将对应的double数组的元素组成pair压栈返回即可
            results.push_back(make_pair(i, f[n][i]));
 
        return results;
    }
};
