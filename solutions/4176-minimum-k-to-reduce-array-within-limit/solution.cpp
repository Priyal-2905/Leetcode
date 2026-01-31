
class Solution {
public:
    int countOps(vector<int> &nums,int k){
        int ops = 0;
        for(int n : nums){
            ops += (n+k - 1)/k;
        }
        return ops;
    }
    int minimumK(vector<int>& nums) {
        int low = 1;
        int high = 100000;

        int res = high;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(countOps(nums,mid) <= 1LL*mid*mid){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            } 
        }
        return res;
    }
};
