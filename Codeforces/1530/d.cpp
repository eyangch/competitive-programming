#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[200000], ans[200000];
bool f[200000], fp[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            a[i]--;
        }
        fill(f, f+N, 0);
        fill(fp, fp+N, 0);
        vector<int> non;
        for(int i = 0; i < N; i++) fp[a[i]] = 1;
        for(int i = 0; i < N; i++) if(!fp[i]) non.push_back(i);
        vector<int> left;
        int K = 0;
        for(int i : non){
            if(f[a[i]]) left.push_back(i);
            else ans[i] = a[i], f[a[i]] = 1, K++;
        }
        for(int i = 0; i < N; i++){
            if(!fp[i]) continue;
            if(f[a[i]]) left.push_back(i);
            else ans[i] = a[i], f[a[i]] = 1, K++;
        }
        sort(left.begin(), left.end());
        int ptr = 0, ptr2 = N-1;
        for(int i : left){
            while(f[ptr]) ptr++;
            while(f[ptr2]) ptr2--;
            if(ptr2 == i) f[ptr] = 1, ans[i] = ptr++;
            else f[ptr2] = 1, ans[i] = ptr2--;
        }
        moo << K << endl;
        for(int i = 0; i < N; i++){
            moo << ans[i]+1 << ' ';
        }
        moo << endl;
    }
}
