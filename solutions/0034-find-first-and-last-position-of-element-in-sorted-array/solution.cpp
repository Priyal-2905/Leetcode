class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid=0;
        bool present =false;

        while(start <= end){
            mid = (start+end)/2;

            if(nums[mid]==target) {present = true; break;}
            else if(nums[mid]<target){start = mid+1;}
            else
                end = mid-1;
        }

        if(present){
            end =start = mid;
            
            while(start >0 && nums[start]==nums[start-1])
                start--;

            while(end <nums.size()-1 && nums[end]==nums[end+1])
                end++;

            return {start,end};
        }
        else
            return {-1,-1};
        

    }
};
