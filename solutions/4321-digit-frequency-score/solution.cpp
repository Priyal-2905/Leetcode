class Solution {
public:
    
    int digitFrequencyScore(int n) {
        unordered_map<int,int> freq;

        while(n > 0){
            freq[n%10]++;
            n = n/10;
        }
        int res = 0;

        for(auto it : freq){
            res += it.first*it.second;
        }
        return res;
    }
};
