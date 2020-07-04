#include <bits/stdc++.h>

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int a[N];
        int mex[N+1];
        fill(mex, mex+N+1, 0);
        for(int i = 0; i < N; i++){
            cin >> a[i];   
            mex[a[i]]++;
        }
        bool good = true;
        vi idxs;
        while(good){
            good = false;
            for(int i = 1; i < N; i++){
                if(a[i] < a[i-1]){
                    good = true;
                }
            }
            if(!good){
                break;
            }
            int nmex;
            bool good = false;
            for(nmex = 0; nmex < N; nmex++){
                if(mex[nmex] == 0){
                    good = true;
                    mex[a[nmex]]--;
                    a[nmex] = nmex;
                    mex[nmex]++;
                    idxs.push_back(nmex);
                    break;
                }
            }
            if(!good){
                for(int i = 0; i < N; i++){
                    if(a[i] != i){
                        mex[N]++;
                        mex[a[i]]--;
                        a[i] = N;
                        idxs.push_back(i);
                        break;
                    }
                }
            }
            //for(int i : mex) cout << i << " ";
            //cout << endl;
        }
        cout << idxs.size() << endl;
        for(int i : idxs) cout << i+1 << " ";
        cout << endl;
    }
    return 0;
}


