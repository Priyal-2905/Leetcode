class Solution {
public:
    int convert(string s){
        int n = s.length();
        int res = 0;

        for(int i = 0;i < n;i++){
            res *= 2;
            res += (s[i] - '0');
        }
        return res;
    }
    string convert2(int num, int n){
        string s(n,'0');

        for(int i = n-1; i >= 0; i--){
            if(num & 1) s[i] = '1';
            num >>= 1;
        }
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> deci;

        for(int i = 0;i < n;i++){
            int t = convert(nums[i]);
            deci.push_back(t);
        }
        sort(deci.begin(),deci.end());

        int missing = 0;
        for(int i = 0; i < n; i++){
            if(deci[i] == missing) missing++;
        }

        return convert2(missing,n);
    }
};
