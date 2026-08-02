class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        double ratio = a /(double)b;
        int res = 0;

        for(int i = 0;i < n;i++){
            int odd = 0;
            int even = 0;
            for(int j = i;j < n;j++){
                if(nums[j] % 2){
                    odd++;
                }else{
                    even++;
                }

                if(odd > 0){
                    double r = even/(double)odd;
                    if(r <= ratio){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
