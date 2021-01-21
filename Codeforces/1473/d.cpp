#include <bits/stdc++.h>

using namespace std;

struct st{
    function<int(int, int)> f;
    int st[20][200005];
    int lg2[200005];
    void init(){
        lg2[1] = 0;
        for(int i = 2; i < 200005; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
    void upd(int x){
        for(int i = 1; i < 20; i++){
            for(int j = 0; j + (1<<i) - 1 < x; j++){
                st[i][j] = f(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int qry(int l, int r){
        int p2 = lg2[r-l+1];
        return f(st[p2][l], st[p2][r-(1<<p2)+1]);
    }
};

int m1(int a, int b){return min(a, b);}
int m2(int a, int b){return max(a, b);}

int T;
int N, M;
int pfx[200005];
string s;
st a, b;

int32_t main(){
    a.f = m1, b.f = m2;
    a.init(), b.init();
    cin >> T;
    while(T--){
        cin >> N >> M;
        cin >> s;
        pfx[0] = 0;
        for(int i = 1; i <= N; i++){
            pfx[i] = pfx[i-1] + (s[i-1] == '+' ? 1 : -1);
        }
        copy(pfx, pfx+N+1, a.st[0]);
        copy(pfx, pfx+N+1, b.st[0]);
        a.upd(N+1), b.upd(N+1);
        for(int i = 0; i < M; i++){
            int l, r; cin >> l >> r;
            int x1 = a.qry(0, l-1);
            int x2 = b.qry(0, l-1);
            int y1 = pfx[l-1], y2 = pfx[l-1];
            if(r < N){
                y1 = a.qry(r+1, N) + pfx[l-1] - pfx[r];
                y2 = b.qry(r+1, N) + pfx[l-1] - pfx[r];
            }
            cout << max(x2, y2) - min(x1, y1) + 1 << endl;
        }
    }
}
