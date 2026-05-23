class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        
        for(int x = 0;x < k;x++){
            for(int y = 0;y < k;y++){
                if(x == y){continue;}
                int op = 0;
                for(int i = 0;i < n;i++){
                    int r = nums[i]%k;
                    if(i % 2 ){
                        int d = abs(y - r);
                        op += min(d,k-d);
                    }
                    else{
                        int d = abs(x-r);
                        op += min(d,k-d);
                    }  
                }
                res = min(res,op);
            }
        }
        return res;
    }
};
