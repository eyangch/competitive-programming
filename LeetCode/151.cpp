class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0){
            return "";
        }
        stringstream ss(s);
        vector<string> sss;
        string tmp;
        while(getline(ss, tmp, ' ')){
            if(tmp != "")
                sss.push_back(tmp);
        }
        if(sss.size() == 0){
            return "";
        }
        for(int i = 0; i < sss.size() / 2; i++){
            tmp = sss[i];
            sss[i] = sss[sss.size() - i - 1];
            sss[sss.size() - i - 1] = tmp;
        }
        string ret = "";
        for(int i = 0; i < sss.size() - 1; i++){
            ret += sss[i] + " ";
        }
        ret += sss[sss.size() - 1];
        return ret;
    }
};