class Solution {
public: 
    bool check(vector<int>& nums,int k,int sum){
        int sub = 1;
        int curr = 0;

        for(int i = 0;i < nums.size();i++){
            if(curr + nums[i] > sum) {
                sub++;
                curr = 0;
            }
            curr += nums[i];
        }

        return sub <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = high - (high-low)/2;
            bool flag = check(nums,k,mid);

            if(flag){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
