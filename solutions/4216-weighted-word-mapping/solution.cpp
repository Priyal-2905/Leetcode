class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        for(int i = 0;i < words.size();i++){
            string w = words[i];
            int wei = 0;
            for(int j = 0;j < w.length();j++){
                wei += (weights[w[j]-'a']);
            }
            wei = wei%26;
            res.push_back('z' - wei);
        }
        return res;
    }
};
