class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i + 2 * k <= n; i++) {
        bool first = true, second = true;

        for (int j = i + 1; j < i + k;j++) {
            if (arr[j] <= arr[j - 1]) {
                first = false;
                break;
            }
        }
        for (int j = i + k + 1;j < i + 2 * k;j++) {
            if (arr[j] <= arr[j - 1]) {
                second = false;
                break;
            }
        }

        if (first && second)
            return true;
    }

    return false;
}
    
};
