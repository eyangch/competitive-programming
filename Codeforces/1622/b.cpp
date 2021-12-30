#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, P[200000], ans[200000];
string S;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> P[i];
        eat >> S;
        int lk = 0;
        for(int i = 0; i < N; i++) lk += (S[i] - '0');
        int dl = N - lk;
        vector<int> li, di;
        for(int i = 0; i < N; i++){
            if(S[i] == '0'){
                di.push_back(i);
            }else{
                li.push_back(i);
            }
        }
        sort(li.begin(), li.end(), [](int a, int b){
            return P[a] < P[b];
        });
        sort(di.begin(), di.end(), [](int a, int b){
            return P[a] < P[b];
        });
        int cnt = 0;
        for(int i : di){
            ans[i] = ++cnt;
        }
        for(int i : li){
            ans[i] = ++cnt;
        }
        for(int i = 0; i < N; i++) moo << ans[i] << ' ';
        moo << endl;
    }
}
