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

bool compsec(pair<pii, int> a, pair<pii, int> b){
    return (a.first.second < b.first.second);
}

int main(){
    int n; cin >> n;
    pair<pii, int> v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i + 1;    
    }
    sort(v, v + n);
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, decltype(&compsec)> pq(compsec);
    int idx = 0;
    int m; cin >> m;
    pii tb[m];
    for(int i = 0; i < m; i++){
        cin >> tb[i].first;
        tb[i].second = i + 1;
    }
    sort(tb, tb + m);
    int s1 = 0, s2 = 0;
    vector<pii> s;
    for(int i = 0; i < m; i++){
        while(idx < n && v[idx].first.first <= tb[i].first){
            pq.push(v[idx]);    
            idx++;
        }
        if(pq.size() > 0){
            s1++;
            s2 += pq.top().first.second;
            s.push_back(pii(pq.top().second, tb[i].second));
            pq.pop();
        }
    }
    cout << s1 << " " << s2 << endl;
    for(int i = 0; i < s1; i++){
        cout << s[i].first << " " << s[i].second << endl;
    }
    return 0;
}


