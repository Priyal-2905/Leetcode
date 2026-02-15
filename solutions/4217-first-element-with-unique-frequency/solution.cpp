class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int x:nums){freq[x]++;}

        unordered_map<int,int> unique;
        for(auto &p:freq){unique[p.second]++;}

        for(int x : nums){
            if(unique[freq[x]] == 1){
                return x;
            }
        }
        return -1;
    }
};
