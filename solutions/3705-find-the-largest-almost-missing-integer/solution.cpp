class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int ,int>freq;
        for(int i = 0;i < n;i++){
            freq[nums[i]]++;
        }
        if(k == nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1){
            int max = -1;
            for(int i=0;i<n;i++){
                if(freq[nums[i]]==1 && nums[i]>max){
                    max = nums[i];
                }
            }
            return max;
        }
        int a = nums[0];
        int b = nums[n-1];
        if(freq[a] == 1 && freq[b] == 1){
            return max(a,b);
        }
        
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
