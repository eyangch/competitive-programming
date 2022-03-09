#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct trie{
    trie *c[31];
    int lvl, v;
    trie(int lvl, int v){
        for(int i = 0; i < 31; i++) c[i] = NULL;
        this->lvl = lvl;
        this->v = v;
    }
    void ins(vector<int> &v, int val){
        if(lvl == (int)v.size()) return;
        if(c[v[lvl]] == NULL){
            c[v[lvl]] = new trie(lvl+1, val);
        }
        c[v[lvl]]->ins(v, val);
    }
    int search(vector<int> &v){
        if(lvl == (int)v.size()) return this->v;
        if(c[v[lvl]] == NULL) return -1;
        return c[v[lvl]]->search(v);
    }
};

int N, A[100], al[100], ar[100];
trie t(0, 0);

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> A[i];
        al[i] = A[i] >> 15;
        ar[i] = A[i] & ((1<<15)-1);
    }
    for(int i = 0; i < (1<<15); i++){
        vector<int> v;
        for(int j = 1; j < N; j++){
            v.push_back((__builtin_popcount(ar[j] ^ i)) - (__builtin_popcount(ar[j-1] ^ i)) + 15);
        }
        t.ins(v, i);
    }
    for(int i = 0; i < (1<<15); i++){
        vector<int> v;
        for(int j = 1; j < N; j++){
            v.push_back(15 - (__builtin_popcount(al[j] ^ i)) + (__builtin_popcount(al[j-1] ^ i)));
        }
        int x = t.search(v);
        if(x > -1){
            moo << (i << 15) + x << endl;
            return 0;
        }
    }
    moo << -1 << endl;
}
