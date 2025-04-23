class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int min=arr[0];
    int res=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<min){
            min =arr[i];
        }

        if(arr[i]-min>res){
            res= arr[i] - min;
        }

    }
    return res==0?-1:res;
    }
};
