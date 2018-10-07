#i//nclude <s ·¢ tring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using std::string;
using std::vector;
using std::map;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};
class Solution {
public:
	static vector<Interval> merge(vector<Interval>& intervals) {
		if (!intervals.size()) return vector<Interval>();
		sort(intervals.begin(), intervals.end(),\
			[](const struct Interval &interv1, const struct Interval &interv2) {
				return interv1.start < interv2.start; });
		vector<Interval> vi;
		auto iv = intervals.begin();
		while (1) {
			auto intervmerg = *iv;
			while (iv->start < intervmerg.end) {
				intervmerg.end = std::max(intervmerg.end, iv->end);
				if (++iv == intervals.end()) { vi.push_back(intervmerg); return vi; };
			}
			vi.push_back(intervmerg);
		}
	}
}; 
int main() {
	Solution::merge(vector<Interval>{ { 8,10 }, { 15,18 }, { 1, 3 }, { 2, 6 }, } );
}
