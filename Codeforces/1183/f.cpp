#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int Q, N, a[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> Q;
    while(Q--){
        eat >> N;
        set<int> s;
        for(int i = 0; i < N; i++){
            int x; eat >> x;
            s.insert(x);
        }
        N = s.size();
        auto it = s.rbegin();
        for(int i = 0; i < N; i++){
            a[i] = *it++;
        }
        vector<int> tk;
        tk.push_back(a[0]);
        for(int i = 1; i < N; i++){
            bool good = true;
            for(int j : tk){
                if(j % a[i] == 0){
                    good = false;
                    break;
                }
            }
            if(good){
                tk.push_back(a[i]);
                if((int)tk.size() == 3) break;
            }
        }
        int sum = 0;
        for(int i : tk) sum += i;
        if(N >= 4 && a[1] % a[2] && a[1] % a[3] && a[2] % a[3]){
            sum = max(sum, a[1] + a[2] + a[3]);
        }
        moo << sum << endl;
    }
}
