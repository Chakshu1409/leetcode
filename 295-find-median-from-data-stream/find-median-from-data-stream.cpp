class MedianFinder {
public:

    priority_queue<int,vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if(maxHeap.empty()){
        //     maxHeap.push(num);
        //     return;
        // }
        // if(minHeap.empty()){
        //     minHeap.push(num);
        //     return;
        // }

        // if(maxHeap.size() > minHeap.size()){
        //     if(num >= maxHeap.top()){
        //         minHeap.push(num);
        //     }
        //     else{
        //         int top=maxHeap.top();
        //         maxHeap.pop();
        //         maxHeap.push(num);
        //         minHeap.push(top);
        //     }
        // }
        // else{
        //     if(num >= maxHeap.top() && num<=minHeap.top()){
        //         maxHeap.push(num);
        //     }
        //     else if(num>=maxHeap.top()){
        //         int top=minHeap.top();
        //         minHeap.pop();
        //         maxHeap.push(top);
        //         minHeap.push(num);
        //     }
        //     else{
        //         maxHeap.push(num);
        //     }
        // }

        if(maxHeap.size()==0){
            maxHeap.push(num);
            return;
        }
        if(minHeap.size() == 0){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            return;
        }
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
            if(maxHeap.top() > minHeap.top()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            return;
        }
        if(maxHeap.size() > minHeap.size()){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            return;
        }
    }
    
    double findMedian() {
        if(maxHeap.size() != minHeap.size()){
            return maxHeap.top();
        }

        int top1=maxHeap.top();
        int top2=minHeap.top();

        return (top1+top2)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */