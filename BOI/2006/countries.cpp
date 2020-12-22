#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int x[1000], y[1000], s[1000];
int graph[1000];
char c[1000];

bool lgf(int n1, int d1, int n2, int d2){
    return (n1 * d2) > (d1 * n2);
}

int dfs(int id){
    return (c[id] ? id : dfs(graph[id]));
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> s[i];
    }
    for(int i = 0; i < N; i++){
        int mx1n = 0, mx1d = 1, mx1i = 0;
        int mx2n = 0, mx2d = 1;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            int dsq = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            if(lgf(s[j], dsq, mx1n, mx1d)){
                mx2n = mx1n;
                mx2d = mx1d;
                mx1n = s[j];
                mx1d = dsq;
                mx1i = j;
            }else if(lgf(s[j], dsq, mx2n, mx2d)){
                mx2n = s[j];
                mx2d = dsq;
            }
        }
        if(lgf(mx1n, mx1d, s[i], 1)){
            if((mx1n * mx2d) == (mx2n * mx1d)){
                c[i] = 'D';
            }else{
                graph[i] = mx1i;
            }
        }else{
            c[i] = 'K';
        }
    }
    for(int i = 0; i < N; i++){
        if(c[i]){
            cout << c[i] << endl;
        }else{
            cout << dfs(i)+1 << endl;
        }
    }
}
