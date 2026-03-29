class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(target.begin(),target.end());

        int res = 0;

        for(int i = 1;i <= n;i++){
            if( n % i == 0){
                if(check(nums,target,i)){
                    res += i;
                }
            }
        }
        return res;
    }

    bool check(const vector<int> &nums,const vector<int>& target,int k){
        int n = nums.size();

        for(int i = 0;i < n;i+= k){
            vector<int> curr(nums.begin()+i,nums.begin()+i+k);
            sort(curr.begin(),curr.end());

            for(int j = 0;j < k;j++){
                if(curr[j] != target[i+j] ){return false;}
            }

            int count = 0;
            for(int j = 0;j < k;j++){
                if(nums[i+j] > nums[i+(j+1)%k]){
                    count++;
                }
            }

            if(count  > 1){return false;}
        }
        return true;
    }
};
