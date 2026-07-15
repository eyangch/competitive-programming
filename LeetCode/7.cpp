class Solution {
public:
    int reverse(int x) {
        int x1 = x;
        vector<int> digits;
        while(x1 != 0){
            int a1 = x1 % 10;
            digits.push_back(a1);
            x1 /= 10;
        }
        int ret = 0;
        for(int i = 0; i < digits.size(); i++){
            ret += pow(10, digits.size() - 1 - i) * digits[i];
        }
        if(copysign(1, ret) != copysign(1, x) || ret == INT_MIN || ret == INT_MAX){
            return 0;
        }
        return ret;
    }
};