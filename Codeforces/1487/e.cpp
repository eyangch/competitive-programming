#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int N1, N2, N3, N4, a[150000], b[150000], c[150000], d[150000], M1, M2, M3;
set<int> g1[150000], g2[150000], g3[150000];
vector<int> id;

void in1(int N, int (&x)[150000]){
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
}

void in2(int M, set<int> (&g)[150000]){
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        g[x-1].insert(y-1);
    }
}

void calc(int N, int (&x)[150000], set<int> (&g)[150000], int (&y)[150000]){
    for(int i = 0; i < N; i++){
        int add = 1e9;
        for(int j : id){
            if(g[i].count(j)) continue;
            add = y[j];
            break;
        }
        x[i] += add;
    }
    id.clear();
    for(int i = 0; i < N; i++){
        id.push_back(i);
    }
    sort(id.begin(), id.end(), [&x](int a, int b){
        return x[a] < x[b];
    });
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N1 >> N2 >> N3 >> N4;
    in1(N1, a), in1(N2, b), in1(N3, c), in1(N4, d);
    cin >> M1, in2(M1, g1);
    cin >> M2, in2(M2, g2);
    cin >> M3, in2(M3, g3);
    for(int i = 0; i < N4; i++){
        id.push_back(i);
    }
    sort(id.begin(), id.end(), [](int a, int b){
        return d[a] < d[b];
    });
    calc(N3, c, g3, d);
    calc(N2, b, g2, c);
    calc(N1, a, g1, b);
    cout << (a[id[0]] >= 1e9 ? -1 : a[id[0]]) << endl;
}
