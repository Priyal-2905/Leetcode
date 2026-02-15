class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> mp;

        for(int b : bulbs){
            mp[b]++;
        }

        vector<int> res;
        for(auto x:mp){
            if(x.second %2 != 0){
                res.push_back(x.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
