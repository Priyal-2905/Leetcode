class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        vector<int> res;

        for(string chunk:chunks){s += chunk;}

        for(int i = 0;i < s.length();i++){
            char c = s[i];
            
            if(c >= 'a' && c <= 'z'){continue;}
            else if(c == '-'){
                if(i > 0 && i < s.length()-1 &&
                   s[i+1] >= 'a' && s[i+1] <= 'z' 
                   && s[i-1] >= 'a' && s[i-1] <='z'){continue;}
                
                while(i < s.length() && s[i] == '-'){
                    s[i++] = ' ';
                }
                i--;
            }
            else{
                s[i] = ' ';
            }
        }

        unordered_map<string,int> freq;
        string word = "";
        
        for(int i = 0;i < s.length();i++){
            if(s[i]==' '){
                if(!word.empty()){
                    freq[word]++;
                    word = "";
                }
            }
            else{
                word += s[i];
            }
        }
        if(!word.empty()){freq[word]++;}

        for(string q:queries){
            res.push_back(freq[q]);
        }
        return res;
    }
};
