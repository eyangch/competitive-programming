#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

set<int> vis;
vi curr;

void dfs(int idx, int n, map<int, int> pf2){
    auto it = pf2.find(idx);
    it++;
    if(it == pf2.end()){
        if(vis.find(n) == vis.end()){
            curr.push_back(n);
            vis.insert(n);
        }
        return;
    }
    for(; it != pf2.end(); it++){
        int pn = it -> f, occ = it -> s;
        for(int j = 0; j <= occ; j++){
            dfs(pn, n * (int)pow(pn, j), pf2); 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        vi pf;
        for(int i = 2; i <= sqrt(N); i++){
            while(N % i == 0){
                pf.push_back(i);
                N /= i;
            }
        }
        if(N > 1){
            pf.push_back(N);
        }
        if((int)pf.size() == 1){
            cout << pf[0] << endl;
            cout << 0 << endl;
        }else if((int)pf.size() == 2 && pf[0] != pf[1]){
            cout << pf[0] << " " << pf[1] << " " << pf[0] * pf[1] << endl;
            cout << 1 << endl;
        }else{
            int end = pf[0] * pf[pf.size()-1];
            map<int, int> pf2;
            for(int i : pf){
                pf2[i]++;
            }
            for(auto it = pf2.begin(); it != pf2.end(); it++){
                curr.clear();
                vis.clear();
                int x = it -> f;
                int y = it -> s;
                dfs(x, 1, pf2);
                sort(curr.begin(), curr.end());
                for(int j : curr){
                    for(int k = 1; k <= y; k++){
                        if((int)pow(x, k) * j != end){
                            cout << (int)pow(x, k) * j << " ";
                        }
                    }
                }
            }
            cout << end << endl;
            cout << 0 << endl;
        }
    }
    return 0;
}


