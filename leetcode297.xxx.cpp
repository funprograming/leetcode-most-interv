/* leetcode 295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
class MedianFinder {
    // 1   2   3   +  4   5
    //        max    min
    priority_queue<int> maxq;
    priority_queue<int,std::vector<int>,std::greater<int>> minq;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxq.empty()|| maxq.top()>num) maxq.push(num);
        else minq.push(num);
        if(maxq.size()>minq.size()+1){
            minq.push(maxq.top());
            maxq.pop();
        }
        else if(minq.size()>maxq.size()+1){
            maxq.push(minq.top());
            minq.pop();           
        }
    }
    
    double findMedian() {
        if(maxq.size() == minq.size()){
            return (minq.top()+maxq.top())/2.0;
        }else{
            return maxq.size()>minq.size()? maxq.top():minq.top();
        }
    }
};