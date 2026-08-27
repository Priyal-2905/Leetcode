class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> freq;
        for (char c : s) freq[c]++;

        int n = s.size();
        string ans;

        for (int i = 0; i < n; i++) {
            if (freq[target[i]]) {
                ans += target[i];
                freq[target[i]]--;
            } else {
                char c = target[i] + 1;

                while (c <= 'z' && !freq[c])
                    c++;

                if (c <= 'z') {
                    freq[c]--;
                    ans += c;

                    for (auto [ch, f] : freq)
                        ans.append(f, ch);

                    return ans;
                }

                break;
            }
        }

        int i = ans.size() - 1;

        while (i >= 0) {
            freq[ans[i]]++;

            char c = ans[i] + 1;

            while (c <= 'z' && !freq[c])
                c++;

            if (c <= 'z') {
                string res = ans.substr(0, i);
                res += c;
                freq[c]--;

                for (auto [ch, f] : freq){
                    res.append(f, ch);
                }
                return res;
            }
            i--;
        }
        return "";
    }
};
