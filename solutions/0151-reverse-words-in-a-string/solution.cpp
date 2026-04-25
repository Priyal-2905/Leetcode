class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i <= j && s[i] == ' ') i++;
        while (j >= i && s[j] == ' ') j--;

        string res = "";

        while (i <= j) {
            int k = j;
            while (k >= i && s[k] != ' ') k--;

            res += s.substr(k + 1, j - k);
            if (k > i) res += " ";

            while (k >= i && s[k] == ' ') k--;
            j = k;
        }
        return res;
    }
};
