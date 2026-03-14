class Solution {
public:
    void build(string curr, int n, vector<string>& store) {
        if (curr.length() == n) {
            store.push_back(curr);
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (curr == "" || curr.back() != c) {
                build(curr + c, n, store);
            }
        }
    }
                                                                                                            
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> store;

        build(curr,n,store);
        sort(store.begin(),store.end());

        if(k > store.size()){return "";}

        return store[k-1];
    }
};
