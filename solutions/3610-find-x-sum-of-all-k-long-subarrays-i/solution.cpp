class Solution {
public:
    int calcXSum(unordered_map<int,int>& mp, int x) {
        vector<pair<int,int>> v; 
        v.reserve(mp.size());

        for(auto &p : mp) 
            v.push_back({p.second, p.first});

        sort(v.begin(), v.end(), [&](auto &a, auto &b){
            if(a.first != b.first) 
                return a.first > b.first; 
            return a.second > b.second; 
        });

        long long sum = 0;
        int count = 0;

        for(auto &p : v) {
            if(count == x) break;
            sum += 1LL * p.second * p.first; 
            count++;
        }
        return (int)sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int i = 0; i < k; i++) 
            freq[nums[i]]++;
        
        ans.push_back(calcXSum(freq, x));

        for(int i = k; i < n; i++) {
            int out = nums[i - k];
            int in = nums[i];

            freq[out]--;
            if(freq[out] == 0) freq.erase(out);
            freq[in]++;

            ans.push_back(calcXSum(freq, x));
        }
        return ans;
    }
};
