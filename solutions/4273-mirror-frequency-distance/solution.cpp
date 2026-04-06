class Solution {
public:
    char mirror(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return 'a'+'z'-ch;
        }
        else{
            return '0'+'9'-ch;
        }
    }

    int mirrorFrequency(string s) {
        unordered_map<char,int> freq;
        
        for(auto x:s){
            freq[x]++;
        }

        unordered_set<char> visit;
        int res = 0;

        for(auto x : freq){
            char a = x.first;
            char b = mirror(a);

            if(visit.find(a) != visit.end() ){ continue;}
            
            int fa = x.second;
            int fb = freq.count(b) ? freq[b] : 0;

            res += abs(fa -fb);
            visit.insert(a);
            visit.insert(b);
        }

        return res;
    }
};
