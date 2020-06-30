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

int n, m;
int cown[100001];
pii sf[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout); 
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> sf[i].first >> sf[i].second;
    }
    fill(cown, cown + m+1, INT_MAX);
    int ans = 0;
    stack<int> fans;
    for(int i = n-1; i >= 0; i--){
        int curr = cown[sf[i].first];
        cown[sf[i].first] = i;
        while(true){
            if(curr == INT_MAX){
                ans++;
                break;
            }
            if(cown[sf[curr].second] > curr){
                int tmp = curr;
                curr = cown[sf[curr].second];
                cown[sf[tmp].second] = tmp;
            }else{
                break;
            }
        }
        fans.push(ans);
    }
    while(!fans.empty()){
        cout << fans.top() << endl;
        fans.pop();
    }
    return 0;
}


