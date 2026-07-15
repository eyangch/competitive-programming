class Solution {
public:
    map<char, char> jonathanIsCool;
    bool recur(string s){
        if(s.length() == 0){
            return true;
        }
        for(int i = 1; i < s.length(); i++){
            if(jonathanIsCool.find(s[i-1]) -> second == s[i]){
                s.erase(i-1, 2);
                return recur(s);
            }
        }
        return false;
    }
    bool isValid(string s) {
        jonathanIsCool['['] = ']';
        jonathanIsCool['('] = ')';
        jonathanIsCool['{'] = '}';
        return recur(s);
    }
};