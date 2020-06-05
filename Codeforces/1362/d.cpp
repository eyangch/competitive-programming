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
    int n, m; cin >> n >> m;
    vi graph[n];
    unordered_set<int> nums[n];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);   
    }
    vi t[n];
    for(int i = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
        int a; cin >> a;
        t[a-1].push_back(i);
    }
    int order[n];
    int x = 0;
    for(int i = 0; i < n; i++){
        for(int j : t[i]){
            order[x] = j;
            for(int k : graph[j]){
                nums[k].insert(i);
            }
            if(nums[j].find(i) != nums[j].end()){
                cout << -1 << endl;
                return 0;   
            }
            auto it = nums[j].begin();
            for(int k = 0; k < i; k++){
                if(nums[j].find(k) == nums[j].end()){
                    cout << -1 << endl;
                    return 0;
                }
            }
            x++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << order[i] + 1 << " ";
    }cout << endl;
    return 0;
}


