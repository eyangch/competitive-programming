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
    int Q; cin >> Q;
    while(Q--){
        string s; cin >> s;
        int m; cin >> m;
        int b[m];
        for(int i = 0; i < m; i++){
            cin >> b[i];   
        }
        int idxs[m];
        vi indicies;
        int mcnt = 0;
        for(int cnt = 0; true; cnt++){
            vi zeros;
            for(int i = 0; i < m; i++){
                if(b[i] == 0){
                    zeros.push_back(i); 
                }
            }
            if((int)zeros.size() == 0){
                break;
            }
            for(int i : zeros){
                idxs[i] = cnt;
                b[i] = -1;
                for(int j = 0; j < m; j++){
                    b[j] -= abs(i-j);
                }
            }
            indicies.push_back((int)zeros.size());
            mcnt = cnt+1;
        }
        map<char, int> cmap;
        vector<char> cvec;
        for(char i : s){
            cmap[i]++;
        }
        for(auto it = cmap.begin(); it != cmap.end(); it++){
            cvec.push_back(it -> first);
        }
        char out[m];
        int stidx = (int)cvec.size();
        for(int i = 0; i < mcnt; i++){
            stidx--;
            while(cmap[cvec[stidx]] < indicies[i]){
                stidx--;
            }
            for(int j = 0; j < m; j++){
                if(idxs[j] == i){
                    out[j] = cvec[stidx];
                }
            }
        }
        for(char i : out) cout << i;
        cout << endl;
    }
    return 0;
}


