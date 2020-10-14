#include <bits/stdc++.h>
#include "memory.h"
#include "grader.h"
#define f first
#define s second

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

void play(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    char card[50];
    for(int i = 0; i < 50; i++){
        card[i] = faceup(i+1);
    }
    bool vis[50];
    fill(vis, vis+50, false);
    for(int i = 0; i < 50; i++){
        if(vis[i]) continue;
        for(int j = i+1; j < 50; j++){
            if(vis[j]) continue;
            if(card[i] == card[j]){
                faceup(i+1);
                faceup(j+1);
                vis[i] = vis[j] = true;
                break;
            }
        }
    }
}


