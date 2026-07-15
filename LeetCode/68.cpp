class Solution {
public:
    string generateLineSimple(vector<string> &words, int width){
        string res;
        for(int i = 0; i < words.size(); i++){
            if(i) res += ' ';
            res += words[i];
        }
        res += string(width - res.size(), ' ');
        return res;
    }
    string generateLine(vector<string> &words, int len, int width){
        int n_spaces = words.size() - 1;
        len -= words.size();
        if(n_spaces == 0){
            return generateLineSimple(words, width);
        }
        int spaces_0 = (width - len) / n_spaces;
        int rem = (width - len) % n_spaces;
        string res;
        for(int i = 0; i < words.size(); i++){
            res += words[i];
            if(i < words.size()-1){
                if(rem-- > 0){
                    res += string(spaces_0 + 1, ' ');
                }else{
                    res += string(spaces_0, ' ');
                }
            }
        }
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;
        vector<string> cur;
        int cur_len = 0;
        for(string &word : words){
            if(cur_len + word.size() > maxWidth){
                results.push_back(generateLine(cur, cur_len, maxWidth));
                cur.clear();
                cur_len = 0;
            }
            cur.push_back(word);
            cur_len += word.size() + 1;
        }
        results.push_back(generateLineSimple(cur, maxWidth));
        return results;
    }
};