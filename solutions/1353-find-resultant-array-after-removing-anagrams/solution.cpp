class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1 ; i < words.size() ;i++){
            string comp = result.back();
            string curr = words[i];

            sort(comp.begin(),comp.end());
            sort(curr.begin(),curr.end());

            if(comp != curr){result.push_back(words[i]);}
        }

        return result;
    }
};
