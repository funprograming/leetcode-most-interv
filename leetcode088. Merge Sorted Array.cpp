/* leetcode088. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n) return;
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
		// 由高到低，避免覆盖
        while(j>=0){
            if(i<0 || nums1[i]<nums2[j]){
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (!n) return;
		int i = 0;
		int j = 0;
		int k = 0;
		int *p = new int[m];
		for (int x = 0; x < m; x++) {
			p[x] = nums1[x];
		}

		while (i<m && j<n) {
			if (p[i]<nums2[j]) {
				nums1[k++] = p[i++];
			}
			else {
				nums1[k++] = nums2[j++];
			}
		}
		while (i<m) nums1[k++] = p[i++];
		while (j<n) nums1[k++] = nums2[j++];				
    }
};