class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0,counter = 0;

        for(int i = 0;i < events.size() && counter < 10;i++){
            string c = events[i];

            if(c == "W"){counter++;}
            else if(c == "WD"){score++;}
            else if(c == "NB"){score++;}
            else{
                score += stoi(c);
            }
        }
        return {score,counter};
    }
};
