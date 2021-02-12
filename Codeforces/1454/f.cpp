#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct spt{
    int lg2[200005], st[20][200005];
    function<int(int, int)> f;
    spt(function<int(int, int)> vf){
        f = vf;
        lg2[1] = 0;
        for(int i = 2; i <= 200000; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
    void init(int N, int (&a)[200000]){
        copy(a, a+N, st[0]);
        for(int i = 1; i <= lg2[N]; i++){
            for(int j = 0; j + (1 << i) - 1 < N; j++){
                st[i][j] = f(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int qry(int l, int r){
        int l2 = lg2[(r - l + 1)];
        return f(st[l2][l], st[l2][r - (1<<l2) + 1]);
    }
};

spt *spt1, *spt2;
int T, N, a[200000];
map<int, vector<int>> occ, og;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    function<int(int, int)> m1 = [](int a, int b){return min(a, b);}, m2 = [](int a, int b){return max(a, b);};
    cin >> T;
    spt1 = new spt(m1), spt2 = new spt(m2);
    while(T--){
        cin >> N;
        occ.clear(), og.clear();
        for(int i = 0; i < N; i++){
            cin >> a[i];
            occ[a[i]].push_back(i);
            og[a[i]].push_back(i);
        }
        set<int> id1, id2;
        for(int i = 0; i < N; i++){
            id1.insert(i);
        }
        id1.insert(-1);
        id2.insert(N);
        spt1->init(N, a), spt2->init(N, a);
        bool no = true;
        for(int i = 0; i < N-2; i++){
            int mx = spt2->qry(0, i);
            while(!occ.empty() && occ.begin()->first <= mx){
                for(int j : occ.begin()->second){
                    id1.erase(j);
                }
                occ.erase(occ.begin());
            }
            while(!og.empty() && og.begin()->first < mx){
                for(int j : og.begin()->second){
                    id2.insert(j);
                }
                og.erase(og.begin());
            }
            auto it_rb = id2.upper_bound(i);
            if(it_rb == id2.end()) continue;
            int rb = *it_rb;
            auto it_lb = id1.end();
            if(it_lb == id1.begin()) continue;
            it_lb--;
            int lb = *it_lb;
            if(rb < lb) continue;
            auto it_fo = upper_bound(og[mx].begin(), og[mx].end(), i);
            if(it_fo == og[mx].end()) continue;
            int fo = max(lb, *it_fo);
            auto it_so = upper_bound(og[mx].begin(), og[mx].end(), fo);
            if(it_so == og[mx].end()) continue;
            int so = min(rb, *it_so);
            if(fo > so) continue;
            if(spt1->qry(i+1, fo) != mx || spt2->qry(fo+1, N-1) != mx) continue;
            cout << "YES" << endl << i+1 << " " << fo - i << " " << N - (fo - i) - (i+1) << endl;
            no = false;
            break;
        }
        if(no) cout << "NO" << endl;
    }
}
