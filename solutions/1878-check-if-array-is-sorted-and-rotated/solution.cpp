class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++){
            bool flag = true;

            for(int j = 1;j < n;j++){
                if(nums[(j+i)%n] < nums[(j+i-1)%n]){
                    flag = false;
                    break;
                }
            }
            if(flag){return true;}
        }
        return false;
    }
};
