#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, M;
vector<int> a[500000], tl[500000], tr[500000], bl[500000], br[500000];
int o[500000];
char ans[500000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int x; eat >> x;
                a[i].push_back(x);
                tl[i].push_back(x);
                tr[i].push_back(x);
                bl[i].push_back(x);
                br[i].push_back(x);
            }
        }
        iota(o, o+N, 0);
        sort(o, o+N, [](int x, int y){
            return a[x][0] < a[y][0];
        });
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(i > 0) tl[o[i]][j] = max(tl[o[i]][j], tl[o[i-1]][j]);
                if(j > 0) tl[o[i]][j] = max(tl[o[i]][j], tl[o[i]][j-1]);
            }
        }
        for(int i = N-1; i >= 0; i--){
            for(int j = 0; j < M; j++){
                if(i < N-1) bl[o[i]][j] = min(bl[o[i]][j], bl[o[i+1]][j]);
                if(j > 0) bl[o[i]][j] = min(bl[o[i]][j], bl[o[i]][j-1]);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = M-1; j >= 0; j--){
                if(i > 0) tr[o[i]][j] = min(tr[o[i]][j], tr[o[i-1]][j]);
                if(j < M-1) tr[o[i]][j] = min(tr[o[i]][j], tr[o[i]][j+1]);
            }
        }
        for(int i = N-1; i >= 0; i--){
            for(int j = M-1; j >= 0; j--){
                if(i < N-1) br[o[i]][j] = max(br[o[i]][j], br[o[i+1]][j]);
                if(j < M-1) br[o[i]][j] = max(br[o[i]][j], br[o[i]][j+1]);
            }
        }
        bool done = false;
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                int mxl = tl[o[j-1]][i-1];
                int mnl = bl[o[j]][i-1];
                int mxr = br[o[j]][i];
                int mnr = tr[o[j-1]][i];
                if(mxl < mnl && mxr < mnr){
                    moo << "YES" << endl;
                    for(int k = 0; k < j; k++){
                        ans[o[k]] = 'B';
                    }
                    for(int k = j; k < N; k++){
                        ans[o[k]] = 'R';
                    }
                    for(int k = 0; k < N; k++){
                        moo << ans[k];
                    }
                    moo << ' ' << i << endl;
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        if(!done) moo << "NO" << endl;
        for(int i = 0; i < N; i++){
            a[i].clear();
            tl[i].clear();
            tr[i].clear();
            bl[i].clear();
            br[i].clear();
        }
    }
}
