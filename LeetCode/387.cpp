class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> jonathanIsREALLYreallyREALLYreallyREALLYcool;
        for(int i = 0; i < 26; i++){
            pair<char, int> in ((char)(i + 97), 0);
            jonathanIsREALLYreallyREALLYreallyREALLYcool.insert(in);
        }
        for(int i = 0; i < s.length(); i++){
            jonathanIsREALLYreallyREALLYreallyREALLYcool[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(jonathanIsREALLYreallyREALLYreallyREALLYcool.find((char)(s[i])) -> second == 1){
                return i;
            }
        }
        return -1;
    }
};