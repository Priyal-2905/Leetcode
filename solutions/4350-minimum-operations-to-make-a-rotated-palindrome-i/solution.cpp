class Solution {
public:
    int check(string t,int start,int n){
        int end = start+n-1;
        int val = 0;
        while(start < end){
            int a = abs(t[start]-t[end]);
            int b = 26 - a;
            val += min(a,b);
            start++;
            end--;
        }
        return val;   
        
    }
    int minOperations(string s) {
        int n = s.length();
        string t = s+s;
        int mini = 1e9;


        for(int i = 0;i < n;i++){
            int curr = check(t,i,n);

            mini = min(curr+i,mini);
        }
        return mini;
    }
};
