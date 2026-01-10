class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if( n<=1 || numRows==1){return s;}

        vector<string> v(numRows);
        int index = 0,diff = -1;
        for(int i = 0;i < n;i++){
            if(index == 0){
                diff = 1;
            }
            if(index == numRows-1){
                diff = -1;
            }

            v[index] += (s[i]);
            index += diff;
        }
        string res = "";
        
        for(string s:v){
            res += s;
        }

        return res;
    }
};
