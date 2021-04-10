#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string s[1000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    for(int tc = 1; tc <= T; tc++){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> s[i];
        }
        int y = 0;
        for(int i = 1; i < N; i++){
            int z = s[i-1].length() - s[i].length();
            if(z < 0) continue;
            string cur = s[i];
            string prev = s[i];
            for(int j = 0; j < z; j++) cur += '9';
            if(cur <= s[i-1]){
                for(int j = 0; j <= z; j++){
                    s[i] += '0';
                }
                y += z+1;
                continue;
            }
            for(int j = 0; j < z; j++) s[i] += '0';
            while(true){
                if(s[i] > s[i-1]) break;
                for(int j = s[i].length()-1; j >= 0; j--){
                    if(s[i][j] == '9') s[i][j] = '0';
                    else{
                        s[i][j]++;
                        break;
                    }
                }
            }
            for(int j = 0; j < (int)s[i].size(); j++){
                if(j >= prev.size() || s[i][j] != prev[j]) y++;
            }
        }
        moo << "Case #" << tc << ": " << y << endl;
    }
}
