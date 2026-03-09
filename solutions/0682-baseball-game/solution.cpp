class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int n = operations.size();
        int sum = 0;

        for(string op:operations){
            if(op == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);
            }
            else if(op == "D"){
                int a = s.top();
                s.push(2*a);
            }
            else if(op == "C"){
                s.pop();
            }
            else{
                int a = stoi(op);
                s.push(a);
            }
        }
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
