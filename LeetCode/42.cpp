class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int water = 0;
        set<int> wh;
        for(int i = 0; i < height.size(); i++){
            if(height[i] != 0){
                wh.insert(height[i]);
            }
        }
        int ch = 0;
        int x = *max_element(height.begin(), height.end());
        while(ch != x){
            //cout << *max_element(height.begin(), height.end()) << endl;
            bool trap = false;
            int trapn = 0;
            int sub = *wh.begin() - ch;
            for(int i = 0; i < height.size(); i++){
                if(height[i] > 0 && trap){
                    trap = false;
                    trapn = 0;
                }
                if(trap){
                    water += sub;
                    trapn += sub;
                }
                if(height[i] > 0 && !trap){
                    trap = true;
                }
            }
            if(trap){
                water -= trapn;
            }
            ch = *wh.begin();
            wh.erase(wh.begin());
            for(int i = 0; i < height.size(); i++){
                height[i] -= sub;
            }
        }
        return water;
    }
};