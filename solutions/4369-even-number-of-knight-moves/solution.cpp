class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int t1 = (start[0] + start[1])%2;
        int t2 = (target[0] + target[1])%2;

        return (t1 == t2);
    }
};
