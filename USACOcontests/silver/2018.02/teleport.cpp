#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int N; cin >> N;
    ll xi[N], yi[N];
    vi p1, m2;
    for(int i = 0; i < N; i++){
        cin >> xi[i] >> yi[i];
        if(xi[i] == 0 || signbit(xi[i]) != signbit(yi[i])){
            p1.push_back(yi[i] * 2);
            p1.push_back(0);
            m2.push_back(yi[i]);
        }else{
            if(yi[i] < 0 && yi[i] < 2 * xi[i]){
                ll dist = yi[i] - xi[i] * 2;
                p1.push_back(yi[i] + dist);
                p1.push_back(yi[i] - dist);
                m2.push_back(yi[i]);
            }else if(yi[i] > 0 && yi[i] > 2 * xi[i]){
                ll dist = yi[i] - xi[i] * 2;
                p1.push_back(yi[i] + dist);
                p1.push_back(yi[i] - dist);
                m2.push_back(yi[i]);
            }
        }
    }
    sort(p1.begin(), p1.end());
    sort(m2.begin(), m2.end());
    ll delta = 0;
    ll pc = 0, mc = 0;
    ll prev = 0;
    ll acc = 0;
    ll ans = 0;
    while(pc < (int)p1.size() || mc < (int)m2.size()){
        bool doP = false;
        if(pc >= (int)p1.size()){
            doP = false;
        }else if(mc >= (int)m2.size()){
            doP = true;
        }else{
            doP = (p1[pc] <= m2[mc]);
        }
        if(doP){
            acc += delta * (p1[pc] - prev);
            ans = max(ans, acc);
            prev = p1[pc];
            delta++;
            pc++;
        }else{
            acc += delta * (m2[mc] - prev);
            ans = max(ans, acc);
            prev = m2[mc];
            delta -= 2;
            mc++;
        }
    }
    ll nm_total = 0;
    for(int i = 0; i < N; i++){
        nm_total += abs(xi[i] - yi[i]);
    }
    cout << nm_total - ans << endl;
    return 0;
}


