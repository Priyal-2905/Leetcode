class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        bool skipped = false;
        long long res1 = nums[0];
        long long res2 = 0;

        for(int i = 1;i < nums.size();i++){
            long long t1 = 0,t2 = max(res1,res2);

            if(colors[i] == colors[i-1]){
                t1 = nums[i] + res2;
            }
            else{
                t1 = nums[i] + max(res1,res2);
            }
            
            res1 = t1;
            res2 = t2;   
            
        }
        return max(res1,res2);
    }
};
