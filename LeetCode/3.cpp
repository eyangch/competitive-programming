class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        unordered_set<char> used;
        int i = 0;
        int j = 0;
        int ret = 0;
        while(j < s.length() && i < s.length()){
            if(used.find(s[j]) == used.end()){
                used.insert(s[j++]);
                //j++;
                ret = max(ret, (j - i));
            }else{
                used.erase(s[i]);
                i++;
            }
           // cout << i << " " << j << endl;
        }
        return ret;
    }
};