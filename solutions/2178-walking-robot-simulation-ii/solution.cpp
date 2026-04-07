class Robot {
private:
    int w,h;
    int i,j;
    int dir; //direction : 0-north 1-east 2-south 3-west

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        i = 0; j = 0;
        dir = 1;
    }
    
    void step(int num) {
        int cycle = 2 * (w + h) - 4;
        num %= cycle;

        if (num == 0 && i == 0 && j == 0) {
            dir = 2;
            return;
        }

        if (num == 0) num = cycle;

        while (num--) {
            if (dir == 1) {
                if (i + 1 < w) i++;
                else { dir = 0; j++; }
            }
            else if (dir == 0) {
                if (j + 1 < h) j++;
                else { dir = 3; i--; }
            }
            else if (dir == 3) {
                if (i - 1 >= 0) i--;
                else { dir = 2; j--; }
            }
            else {
                if (j - 1 >= 0) j--;
                else { dir = 1; i++; }
            }
        }
    }
    
    vector<int> getPos() {
        return {i,j};
    }
    
    string getDir() {
        if(dir == 0) return "North";
        else if(dir == 1) return "East";
        else if(dir == 2) return "South";
        else  return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
