using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int K) {
        int N = s.length();
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                int n0 = 0, n1 = 0;
                for(int k = i; k <= j; k++){
                    if(s[k] == '0') n0++;
                    else n1++;
                }
                if(n0 <= K || n1 <= K) ans++;
            }
        }
        return ans;
    }
};