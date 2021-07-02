#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[100000], b[100000], id[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) eat >> a[i] >> b[i];
    iota(id, id+N, 0);
    sort(id, id+N, [](int x, int y){return b[x] < b[y];});
    int e1 = N-1, e2 = 0;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int cur1 = id[i];
        int cur2 = id[e1];
        if(i > e1) break;
        if(i == e1){
            int lft = a[cur1] - e2;
            if(cnt >= b[cur1]){
                cnt += lft;
                ans += lft;
            }else{
                int rem = b[cur1] - cnt;
                if(rem >= lft){
                    cnt += lft;
                    ans += 2 * lft;
                }else{
                    cnt += lft;
                    ans += 2 * rem + (lft - rem);
                }
            }
            break;
        }
        if(cnt >= b[cur1]){
            cnt += a[cur1];
            ans += a[cur1];
            //moo << i << " "<< ans << " " << cnt << " " << e1 << " " << e2 << endl;
            continue;
        }
        int rem = b[cur1] - cnt;
        if(a[cur2] - e2 <= rem){
            cnt += a[cur2] - e2;
            ans += 2 * (a[cur2] - e2);
            e1--;
            e2 = 0;
            i--;
        }else{
            cnt += rem;
            ans += 2 * rem;
            e2 += rem;
            cnt += a[cur1];
            ans += a[cur1];
        }
        //moo << i << " "<< ans << " " << cnt << " " << e1 << " " << e2 << endl;
    }
    moo << ans << endl;
}
