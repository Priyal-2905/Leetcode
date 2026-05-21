class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;

        for(int n : arr1){
            string s = to_string(n);
            string temp = "";

            for(char c:s){
                temp += c;
                prefix.insert(temp);
            }
        }

        int res = 0;

        for(int n : arr2){
            string s = to_string(n);
            string temp = "";

            for(char c:s){
                temp += c;
                if(prefix.contains(temp)){
                    res = max(res,(int)temp.length());
                }
            }
        }

        return res;

    }
};
