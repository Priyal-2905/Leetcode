class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
       unordered_map<string,int> freq;

        for(auto w : words){
            if(w.size() >= k){
                freq[w.substr(0,k)]++;
            }
        }
    
        int groups = 0;
        for(auto &p : freq){
            if(p.second >= 2) groups++;
        }
    
        return groups;
    }
};
