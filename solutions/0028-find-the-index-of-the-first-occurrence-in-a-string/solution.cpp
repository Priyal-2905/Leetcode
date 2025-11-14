class Solution {
public:
    int strStr(string haystack, string needle) {
        int n2 = needle.length();
        int n1 = haystack.length();

        for(int i = 0;i < n1-n2+1;i++){
            bool flag = true;
            for(int j = 0;j < n2;j++){     
                if(needle[j] != haystack[i+j]){
                    flag = false;
                    break;
                }
            }
            if(flag){return i;}
        }
        return -1;

    }
};
