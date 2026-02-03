class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        if(n == 3){return false;}

        while(i < n-1 && nums[i] < nums[i+1])
            i++;
        if(i == 0){return false;}

        int t1 = i;
        while(i < n-1 && nums[i] > nums[i+1])
            i++;
        
        if(i == t1){return false;}

        int t2 = i;

        while(i < n-1 && nums[i] < nums[i+1])
            i++;
        
        if(i == t2){return false;}

        return (i == n-1);
    }
};
