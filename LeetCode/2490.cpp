class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        string cur;
        char f = '~';
        char l = '~';
        while(getline(iss, cur, ' ')){
            if(l == '~'){
                f = cur[0];
            }else{
                if(cur[0] != l) return false;
            }
            l = cur[cur.length()-1];
        }
        if(f != l){
            return false;
        }
        return true;
    }
};