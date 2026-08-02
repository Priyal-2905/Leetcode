class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int time = 0;
        int n = tasks.size();
        vector<int> res;

        vector<long long> prefix(n+1,0);

        for(int i = 0;i < n;i++){
            prefix[i+1] = prefix[i] + tasks[i];
        }

        long long total = prefix[n];
        long long done = 0;

        for(int shift : shifts){
            if(shift >= total - done){
                done = 0;
                res.push_back(0);
            }else{
                done += shift;
                int comp_task = upper_bound(prefix.begin(),prefix.end(),done) - prefix.begin() - 1;
                res.push_back(n - comp_task);
            }
        }
        return res;
    }
};
