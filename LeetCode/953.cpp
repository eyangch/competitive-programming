class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> wordsN;
        for(int i = 0; i < words.size(); i++){
            int wordc = 0;
            for(int j = 0; j < words[i].length(); j++){
                for(int k = 0; k < 26; k++){
                    if(words[i][j] == order[k]){
                        wordc += (10000000 * (k) / (pow(10, j)));
                        break;
                    }
                }
            }
            cout << wordc << endl;
            wordsN.push_back(wordc);
        }
        for(int i = 1; i < wordsN.size(); i++){
            if(wordsN[i] < wordsN[i - 1]){
                return false;
            }
        }
        return true;
    }
};