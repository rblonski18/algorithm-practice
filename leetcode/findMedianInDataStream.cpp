// find median from data stream
// design a data structure that allows
// addNum and findMedian -> findMedian should
// run in O(1);
//
// idea is to have a min-heap and max-heap. store 
// half of the stream into each heap, grab the median
// by saying: is max-heap bigger (odd num elements) ?
// if so, return max-heap top, else average top of both. 
//
// note: I stole the idea from discussion on lc: priority queue
// in cpp is max-heap by default -> easy min-heap is to enter
// numbers in as their negatives and to deal with them
// accordingly. 

class MedianFinder {
    
    priority_queue<long> small, large;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);
        large.push(-small.top());
        small.pop();
        
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */