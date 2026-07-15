class Solution {
public:
    void pushVal(vector<int> &r, int pv){
        r.push_back(0);
        for(int i = r.size() - 1; i > 0; i--){
            r[i] = r[i-1];
        }
        r[0] = pv;
    }
    int calPoints(vector<string>& ops) {
        vector<int> lround;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "+"){
                pushVal(lround, lround[0] + lround[1]);
                sum += lround[0];
            }else if(ops[i] == "D"){
                pushVal(lround, 2 * lround[0]);
                sum += lround[0];
            }else if(ops[i] == "C"){
                sum -= lround[0];
                lround.erase(lround.begin() + 0);
            }else{
                lround.insert(lround.begin(), stoi(ops[i]));
                sum += lround[0];
            }
        }
        return sum;
    }
};