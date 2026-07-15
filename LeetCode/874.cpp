class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<long long, long long>> os;
        for(vector<int> i : obstacles){
            os.insert({i[0], i[1]});
        }
        long long x = 0, y = 0, dx = 0, dy = 1, ans = 0;
        for(int c : commands){
            if(c == -1){
                dx = -dx;
                swap(dx, dy);
            }else if(c == -2){
                dy = -dy;
                swap(dx, dy);
            }else{
                for(int i = 0; i < c; i++){
                    x += dx, y += dy;
                    if(os.count({x, y})){
                        x -= dx, y -= dy;
                        break;
                    }
                }
                ans = max(ans, x*x+y*y);
            }
        }
        return ans;
    }
};