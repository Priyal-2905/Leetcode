class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;

        for(char c : word){
            freq[c]++;
        }

        vector<pair<int,char>> sorted;

        for(auto it : freq){
            sorted.push_back({it.second,it.first});
        }

        sort(sorted.begin(),sorted.end(),greater<pair<int,int>>());
        int n = sorted.size();
        int res = 0;

        for(int i = 0;i < n;i++){
            int mul = i/8 + 1;

            res += mul*sorted[i].first;
        }

        return res;
    }
};
