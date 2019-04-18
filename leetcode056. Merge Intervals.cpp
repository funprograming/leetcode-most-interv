/* leetcode56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (!intervals.size()) return vector<Interval>();
		sort(intervals.begin(), intervals.end(),\
			[](const struct Interval &interv1, const struct Interval &interv2) {
				return interv1.start < interv2.start; });
		vector<Interval> vi;
		auto iv = intervals.begin();
		while (iv != intervals.end()) {
			auto intervmerg = *iv;
			while (iv != intervals.end() && iv->start <= intervmerg.end) {
				intervmerg.end = std::max(intervmerg.end, iv->end);
                ++iv;
			}
			vi.push_back(intervmerg);
		}
        return vi;
	}
};