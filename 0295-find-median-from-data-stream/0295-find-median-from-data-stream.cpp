class MedianFinder {
public:
    priority_queue<int,vector<int>>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(maxHeap.empty() or num<=maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        //now try to balance both the heaps with size difference being atmost 1:
        int a = maxHeap.size() , b = minHeap.size();
        
        if(a>b and a-b > 1){
            int val = maxHeap.top();maxHeap.pop();
            minHeap.push(val);
        }else if(b>a and b-a >= 1){
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }

    }
    
    double findMedian() {
        int a = maxHeap.size() , b = minHeap.size();

        double ans = 0;
        if(a==b){
            //this is the even case:
            int val1 = maxHeap.top();
            int val2 = minHeap.top();

            ans = (val1 + val2)/2.0;
        }else{
            ans = maxHeap.top();
        }

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */