class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> pq;
        vector<vector<int>> heights, res;

        for (auto b : buildings) {
            int x = b[0];
            int y = b[1];
            int h = b[2];

            heights.push_back({x, -h});
            heights.push_back({y, h});
        }

        sort(heights.begin(), heights.end());
        pq.insert(0);
        int prevHeight = 0;

        for (auto height : heights) {
            int x = height[0];
            int h = height[1];

            if (h < 0) {
                pq.insert(-h);
            } else {
                pq.erase(pq.find(h));
            }

            int currHeight = *pq.rbegin();

            if (currHeight != prevHeight) {
                res.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return res;
    }
};
