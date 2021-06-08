#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        map<pair<int, int>, int> m;
        eat >> N;
        eat >> s;
        int d = 0, k = 0;
        if(s[0] == 'D') d++;
        else k++;
        m.insert({{d, k}, 1});
        moo << 1 << " ";
        for(int i = 1; i < N; i++){
            if(s[i] == 'D') d++;
            else k++;
            int num = d, den = k;
            if(num != 0 && den != 0){
                int g = gcd(num, den);
                num /= g, den /= g;
            }else{
                if(num != 0) num = 1;
                if(den != 0) den = 1;
            }
            int ans = 0;
            if(m.count({num, den})){
                ans = ++m[make_pair(num, den)];
            }else{
                m.insert({{num, den}, 1});
                ans = 1;
            }
            moo << ans << " ";
        }
        moo << endl;
    }
}
