#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

map<int, int> mem;

void dfs(int mloc, int nm, string mask, int loc){
    if(loc == 36){
        mem[mloc] = nm;
        return;
    }
    if(mask[loc] == 'X'){
        mloc |= (1LL << loc);
        dfs(mloc, nm, mask, loc+1);
        mloc &= ~(1LL << loc);
        dfs(mloc, nm, mask, loc+1);
    }else{
        dfs(mloc, nm, mask, loc+1);
    }
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string op, eq, num;
    int ans = 0;
    string mask = "";
    while(cin >> op >> eq >> num){
        if(op == "mask"){
            mask = num;
            reverse(mask.begin(), mask.end());
        }else{
            string tmp = op.substr(4);
            int mloc = stoi(tmp.substr(0, (int)tmp.size()-1));
            int nm = stoi(num);
            for(int i = 0; i < 36; i++){
                if(mask[i] == '1'){
                    mloc |= (1LL << i);
                }
            }
            dfs(mloc, nm, mask, 0);
        }
    }
    for(auto it = mem.begin(); it != mem.end(); it++){
        ans += it -> second;
    }
    cout << ans << endl;
    return 0;
}




