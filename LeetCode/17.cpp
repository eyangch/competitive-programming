class Solution {
public:
    vector<string> ans;
    string cur;
    string M[10] = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    void dfs(string &digits, int index){
        if(index == digits.size()){
            ans.push_back(cur);
            return;
        }
        int x = digits[index]-'0';
        for(char c : M[x]){
            cur += c;
            dfs(digits, index+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        dfs(digits, 0);
        return ans;
    }
};