class Solution {
public:
    bool solve(vector<int>& nums,int low,int high,int total,bool turn){
        if(low > high){
            return total >= 0;
        }
        bool flag;
        if(turn){
            flag = solve(nums,low+1,high,total+nums[low],false) ||
                        solve(nums,low,high-1,total+nums[high],false);
        }else{
            flag = solve(nums,low+1,high,total-nums[low],true) &&
                        solve(nums,low,high-1,total-nums[high],true);
        }
        
        return flag;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n =  nums.size();

        if(n == 1){
            return true;
        }

        return solve(nums,0,n-1,0,true);
    }
};
