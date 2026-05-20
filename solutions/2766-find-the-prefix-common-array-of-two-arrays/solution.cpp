class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> c(n);

        vector<int> freq1(n+1),freq2(n+1);
        for(int i = 0;i < n;i++){
            freq1[A[i]] = 1;
            freq2[B[i]] = 1;
            int count = 0;
            for(int j = 1;j <= n;j++){
                if(freq1[j] == 1 && freq2[j] == 1){count++;}
            }
            c[i] = count;
        }
        return c;
    }
};
