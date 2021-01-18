#include <bits/stdc++.h>
#define int long long

using namespace std;

struct prj{
    int a, b, p, i;
};

struct si_map{
    map<int, int> m;
    void ins(int idx, int v){
        auto it = m.upper_bound(idx);
        if(it != m.begin()){
            it--;
            if(it -> second >= v) return;
        }
        it = m.lower_bound(idx);
        vector<int> rm;
        while(it != m.end() && it -> second <= v){
            rm.push_back(it -> first);
            it++;
        }
        for(int i : rm){
            m.erase(i);
        }
        m[idx] = v;
    }
    int qry(int idx){
        auto it = m.lower_bound(idx);
        if(it == m.begin()) return 0;
        it--;
        return it -> second;
    }
};

int N;
prj s1[200000], s2[200000];
si_map sm;
int dp[200000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s1[i].a >> s1[i].b >> s1[i].p;
        s1[i].i = i;
    }
    copy(s1, s1+N, s2);
    sort(s1, s1+N, [](prj a, prj b){
        if(a.a == b.a) return a.b < b.b;
        return a.a < b.a;        
    });
    sort(s2, s2+N, [](prj a, prj b){
        if(a.b == b.b) return a.a < b.a;
        return a.b < b.b;
    });
    int ptr2 = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        while(ptr2 < N && s2[ptr2].b < s1[i].a){
            sm.ins(s2[ptr2].b, dp[s2[ptr2].i]);
            ptr2++;         
        }
        dp[s1[i].i] = s1[i].p + sm.qry(s1[i].a); 
        ans = max(ans, dp[s1[i].i]);
    }
    cout << ans << endl;
}
