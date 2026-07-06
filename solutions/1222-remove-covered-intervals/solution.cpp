class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
        });
        
        int count = 0;
        int end = 0;
        
        for(auto interval : intervals){
           if(end < interval[1]){
            count++;
            end = interval[1];
           }

        }

        return count;
        
    }
};
