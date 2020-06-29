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

struct state{
    pii loc; 
    int ort; // 0=north, 1=east, 2=south, 3=west
};

int hashState(state &s1, state &s2){
    return s1.loc.first + 10*s1.loc.second + 100*s1.ort + 400*s2.loc.first + 4000*s2.loc.second + 40000*s2.ort;
}

void move(state &s, string (&b)[10]){
    if(s.ort == 0){
        if(s.loc.second == 0 || b[s.loc.first][s.loc.second-1] == '*'){
            s.ort++;
            s.ort %= 4;
        }else{
            s.loc.second--;
        }
    }else if(s.ort == 1){
        if(s.loc.first == 9 || b[s.loc.first+1][s.loc.second] == '*'){
            s.ort++;
            s.ort %= 4;
        }else{
            s.loc.first++;
        }
    }else if(s.ort == 2){
        if(s.loc.second == 9 || b[s.loc.first][s.loc.second+1] == '*'){
            s.ort++;
            s.ort %= 4;
        }else{
            s.loc.second++;
        }
    }else{
        if(s.loc.first == 0 || b[s.loc.first-1][s.loc.second] == '*'){
            s.ort++;
            s.ort %= 4;
        }else{
            s.loc.first--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout); 
    string btmp[10], b[10];
    state cow;
    state farmer;
    for(int i = 0; i < 10; i++){
        cin >> btmp[i];
        for(int j = 0; j < 10; j++){
            if(btmp[i][j] == 'F'){
                farmer.loc = pii(j, i);
                btmp[i][j] = '.';
            }
            if(btmp[i][j] == 'C'){
                cow.loc = pii(j, i);
                btmp[i][j] = '.';
            }
            b[j][i] = btmp[i][j];
        }
    }
    bool been[200000];
    fill(been, been+200000, false);
    int i = 0;
    bool good = true;
    for(; true; i++){
        if(farmer.loc == cow.loc){
            break;
        }
        if(been[hashState(farmer, cow)]){
            good = false;
            break;
        }
        been[hashState(farmer, cow)] = true;
        move(farmer, b);
        move(cow, b);
    }
    if(good){
        cout << i << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
