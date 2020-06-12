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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        auto cmpl = [](pii a, pii b){
            if(a.second-a.first == b.second-b.first){
                return a.first > b.first;
            }
            return (a.second-a.first) < (b.second-b.first);  
        };
        priority_queue<pii, vector<pii>, decltype(cmpl)> pq(cmpl);
        int ans[n];
        int num = 1;
        pq.push(make_pair(0, n-1));
        while(!pq.empty()){
            pii idx = pq.top();
            pq.pop();
            if(idx.second - idx.first < 0){
                break;
            }
            int mid = (idx.first + idx.second) / 2;
            ans[mid] = num;
            num++;
            if(idx.first != idx.second){
                pq.push(make_pair(idx.first, mid - 1));
                pq.push(make_pair(mid + 1, idx.second));
            }
        }
        for(int i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


