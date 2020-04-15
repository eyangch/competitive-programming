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
    int n, m; cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];   
    }
    set<pii> been;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(been.find(pii(i, j)) != been.end()){
                continue;    
            }
            queue<pair<pii, pii>> bfs;
            bfs.push(pair<pii, pii>(pii(i, j), pii(i, j)));
            been.insert(pii(i, j));
            while(!bfs.empty()){
                pair<pii, pii> idx = bfs.front();
                bfs.pop();
                pii curr = idx.first;
                pii prev = idx.second;
                bool qut = false;
                if(curr.first > 0 && s[curr.first - 1][curr.second] == s[curr.first][curr.second] && pii(curr.first - 1, curr.second) != prev){
                    if(been.find(pii(curr.first - 1, curr.second)) != been.end()){
                        qut = true;
                    }
                    been.insert(pii(curr.first - 1, curr.second));
                    bfs.push(pair<pii, pii>(pii(curr.first - 1, curr.second), curr));
                }

                if(curr.first < n-1 && s[curr.first + 1][curr.second] == s[curr.first][curr.second] && pii(curr.first + 1, curr.second) != prev){
                    if(been.find(pii(curr.first + 1, curr.second)) != been.end()){
                        qut = true;
                    }
                    been.insert(pii(curr.first + 1, curr.second));
                    bfs.push(pair<pii, pii>(pii(curr.first + 1, curr.second), curr));
                }

                if(curr.second > 0 && s[curr.first][curr.second - 1] == s[curr.first][curr.second] && pii(curr.first, curr.second - 1) != prev){
                    if(been.find(pii(curr.first, curr.second - 1)) != been.end()){
                        qut = true;
                    }
                    been.insert(pii(curr.first, curr.second - 1));
                    bfs.push(pair<pii, pii>(pii(curr.first, curr.second - 1), curr));
                }

                if(curr.second < m-1 && s[curr.first][curr.second + 1] == s[curr.first][curr.second] && pii(curr.first, curr.second + 1) != prev){
                    if(been.find(pii(curr.first, curr.second + 1)) != been.end()){
                        qut = true;
                    }
                    been.insert(pii(curr.first, curr.second + 1));
                    bfs.push(pair<pii, pii>(pii(curr.first, curr.second + 1), curr));
                }
                if(qut){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}


