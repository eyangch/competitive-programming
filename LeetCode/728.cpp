class Solution {
public:
    bool isSelf(int n){
        string s = to_string(n);
        for(int i = 0; i < s.length(); i++){
            string cs(1, s[i]);
            int td = stoi(cs);
            if(td == 0 || n % td != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> sdn;
        for(int i = left; i <= right; i++){
            if(isSelf(i)){
                sdn.push_back(i);
            }
        }
        return sdn;
    }
};