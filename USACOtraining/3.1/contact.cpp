/*
ID: sireric1
LANG: C++11
TASK: contact
*/

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

bool sortStrings(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int A, B, N; cin >> A >> B >> N;
    string s;
    string tmp;
    while(getline(cin, tmp)){
        s += tmp;
    }
    map<string, int> mp;
    for(int i = A; i <= B; i++){
        for(int j = 0; j <= (int)s.length() - i; j++){
            mp[s.substr(j, i)]++;
        }
    }
    vector<string> loc[200001];
    for(auto it = mp.begin(); it != mp.end(); it++){
        string str = it -> first;
        int occ = it -> second;
        loc[occ].push_back(str);
    }
    for(int i = 200000; i > 0 && N > 0; i--){
        if((int)loc[i].size() > 0){
            N--;
            cout << i << endl;
            sort(loc[i].begin(), loc[i].end(), sortStrings);
            for(int j = 0; j < (int)loc[i].size(); j++){
                cout << loc[i][j];
                if(j != 0 && j != (int)loc[i].size() - 1 && (j+1) % 6 == 0){
                    cout << endl;
                }else if(j != (int)loc[i].size() - 1){
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}


