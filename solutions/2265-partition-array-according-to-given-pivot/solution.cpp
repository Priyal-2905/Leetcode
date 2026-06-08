class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> lesser,greater,ans;
        int equal = 0;

        for(int num : nums){
            if(num == pivot){equal++;}
            else if(num < pivot){lesser.push_back(num);}
            else {greater.push_back(num);}
        }

        for(int x : lesser){ans.push_back(x);}
        for(int i = 0;i < equal;i++){ans.push_back(pivot);}
        for(int x : greater){ans.push_back(x);}

        return ans;
    }
};
