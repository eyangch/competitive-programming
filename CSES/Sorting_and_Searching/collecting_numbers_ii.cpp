#include <bits/stdc++.h>

using namespace std;

int N, M;
int x[200002];
int loc[200002];
bool op[200002];
int ans = 1;

int scfunc(int a, int b){
    int la = x[a], lb = x[b];
    op[la] = op[la+1] = op[lb] = op[lb+1] = true;
    int score = (loc[la] < loc[la-1]) + (loc[la+1] < loc[la]);
    op[la] = op[la+1] = false;
    if(op[lb]) score += (loc[lb] < loc[lb-1]);
    if(op[lb+1]) score += (loc[lb+1] < loc[lb]);
    op[lb] = op[lb+1] = false;
    return score;
}

int32_t main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> x[i];
        loc[x[i]] = i;
    }
    for(int i = 2; i <= N; i++){
        ans += (loc[i] < loc[i-1]);
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        int score = scfunc(a, b);
        swap(x[a], x[b]);
        loc[x[a]] = a;
        loc[x[b]] = b;
        score -= scfunc(a, b);
        ans -= score;
        cout << ans << endl;
    }
}
