class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cur_mod = 1 % k;
        for(int i = 1; i <= k; i++){
            if(cur_mod == 0){
                return i;
            }
            cur_mod = (cur_mod * 10 + 1) % k;
        }
        return -1;
    }
};