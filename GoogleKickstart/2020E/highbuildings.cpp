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
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc << ": ";
        int N, A, B, C; cin >> N >> A >> B >> C;
        if(A == B && B == C && C == 1 && N > 1){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vi ans;
        for(int i = 0; i < A-C; i++){
            ans.push_back(2);
        }
        for(int i = 0; i < C; i++){
            ans.push_back(3);
        }
        for(int i = 0; i < B-C; i++){
            ans.push_back(2);
        }
        if((int)ans.size() > N){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        string strans = "";
        for(int i = 0; i < (int)ans.size(); i++){
            if(i == 1){
                for(int j = 0; j < (N - (int)ans.size()); j++){
                    strans += "1 ";
                }
            }
            if(N <= 2) ans[i]--;
            if(N <= 1) ans[i]--;
            strans += to_string(ans[i]) + " ";
        }
        for(int i = 0; i < (int)strans.length() - 1; i++){
            cout << strans[i];
        }cout << endl;
    }
    return 0;
}


