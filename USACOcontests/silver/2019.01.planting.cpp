#include <bits/stdc++.h>

using namespace std;

#define p(s) cout << (s) << endl
#define FOR(i, x) for(int (i) = 0; i < (x); i++)
#define pb(x) push_back(x)
typedef vector<int> vi;

int main(){
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    int N; fin >> N;
    vi paths[N];
    FOR(i, N-1){
        int a, b; fin >> a >> b;
        paths[a-1].pb(b-1);
        paths[b-1].pb(a-1);
    }
    int ret = 0;
    for(vi i : paths)
        ret = max(ret, (int)i.size());
    fout << ret + 1 << endl;
    return 0;
}
