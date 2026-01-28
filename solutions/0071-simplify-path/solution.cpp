class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        for(int i = 0;i < path.length();i++){
            char c = path[i];
            if( c == '/'){
                continue;
            }
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i++];
            }
            
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(temp);
            }
        }
        string res;
        while(!s.empty()){
            res = "/"+ s.top() + res;
            s.pop();
        }
        if(res.empty()){return "/";}
        return res;
    }
};
