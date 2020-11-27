#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

class trie{
    public:
        trie *c[2];
        trie(){
            this -> c[0] = this -> c[1] = NULL;
        }
        void insert(string str){
            trie *curr = this;
            for(char i : str){
                if(!curr -> c[i-'0']){
                    curr -> c[i-'0'] = new trie();
                }
                curr = curr -> c[i-'0'];
            }
        }
        int search(string str){
            trie *curr = this;
            int ret = 0;
            for(char i : str){
                if(curr -> c[!(i-'0')]){
                    ret = ret * 2 + 1;
                    curr = curr -> c[!(i-'0')];
                }else{
                    ret *= 2;
                    curr = curr -> c[i-'0'];
                }
            }
            return ret;
        }
};

trie *root;

int N;
int pfx[200000];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> pfx[0];
    for(int i = 1; i < N; i++){
        cin >> pfx[i];
        pfx[i] ^= pfx[i-1];
    }
    root = new trie(); 
    root -> insert(bitset<32>(0).to_string());
    int ans = 0;
    for(int i = 0; i < N; i++){
        string curr = bitset<32>(pfx[i]).to_string();
        ans = max(ans, root -> search(curr));
        root -> insert(curr);
    }
    cout << ans << endl;
    return 0;
}


