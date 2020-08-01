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
        int N; cin >> N;
        string a, b; cin >> a >> b;
        int ptr1 = 0, ptr2 = N-1;
        int K = 0;
        vi ans;
        bool fwd = true;
        for(int i = N-1; i >= 0; i--){
            bool first = false;
            if(fwd){
                first = a[ptr1++] - '0';
            }else{
                first = a[ptr2--] - '0';
            }
            bool curr = b[i] - '0';
            if((fwd && first == curr) || (!fwd && first != curr)){
                K++;
                ans.push_back(1);
            }
            K++;
            ans.push_back(i+1);
            fwd = !fwd;
        }
        cout << K << " ";
        for(int i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


