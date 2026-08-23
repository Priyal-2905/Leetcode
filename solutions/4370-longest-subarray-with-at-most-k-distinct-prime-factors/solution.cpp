class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int> spf(maxi+1);

        for(int i = 0;i <= maxi;i++){
            spf[i] = i;
        }

        for(int i = 2;i*i <= maxi;i++){
            if(spf[i] == i){
                for(int j = i*i; j <= maxi; j+= i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        int n = nums.size();
        vector<vector<int>> factors(n);
        for(int i = 0;i < n;i++){
            int val = nums[i];

            while(val > 1){
                int p = spf[val];
                factors[i].push_back(p);
                while(val % p == 0){
                    val /= p;
                }
            }
        }

        unordered_map<int,int> freq;
        int distinct = 0;
        int left = 0,ans = 0;

        for(int right = 0;right < n;right++){

            for(int p : factors[right]){
                if(freq[p] == 0){
                    distinct++;
                }
                freq[p]++;
            }

            while(distinct > k && left <= right){
                for(int p : factors[left]){
                    freq[p]--;
                    if(freq[p] == 0){
                        distinct--;
                    }
                }
                left++;
            }

            if(left <= right && distinct <= k){
                ans = max(ans,right-left+1);
            }
            
        }
        return ans;
             
        
    }
};
