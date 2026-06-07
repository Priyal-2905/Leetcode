class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long energy = 0;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (auto &in : intervals) {
            if (merged.empty() || merged.back()[1] < in[0]) {
                merged.push_back(in);
            } else {
                merged.back()[1] = max(merged.back()[1], in[1]);
            }
        }
        long long req = brightness/3;
        if(brightness %3 != 0){req++;}

        for(auto interval : merged){
            long long len = interval[1] - interval[0] + 1;
            energy += req * len;
        }
        return energy;
        
    }
};
