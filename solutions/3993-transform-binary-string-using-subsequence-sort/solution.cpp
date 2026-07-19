class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> prefix(n);
        int ones = 0;

        for(int i = 0;i < n;i++){
            if(s[i] == '1') ones++;
            prefix[i]= ones;
        }
        vector<bool> res;

        for(string t : strs){
            int fixed1 = 0,vari = 0;

            for(char c : t){
                if(c == '1'){
                    fixed1++;
                }else if(c == '?'){
                    vari++;
                }
            }

            if(ones < fixed1 || ones > fixed1 + vari){
                res.push_back(false);
                continue;
            }

            int need = ones - fixed1;
            int curr1 = 0;
            bool flag = true;

            for(int i = 0;i < n;i++){
                if(t[i] == '1'){
                    curr1++;
                }else if(t[i] == '?'){
                    vari--;
                    if(need > vari){
                        curr1++;
                        need--;
                    }
                }

                if(curr1 > prefix[i]){
                    flag = false;
                    break;
                }
            }
            res.push_back(flag);
        }
        return res;
        
    }
};
