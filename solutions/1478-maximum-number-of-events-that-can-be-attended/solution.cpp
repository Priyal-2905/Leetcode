class Solution {
public:
    static bool myCmp(vector<int>& a, vector<int>& b){
	  return (a[1] < b[1]);
    }

    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, index = 0, n = events.size(), result = 0;
        
        while (!minHeap.empty() || index < n) {
            if (minHeap.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;
            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return result;
    }
};
