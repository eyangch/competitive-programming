#include <bits/stdc++.h>
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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N, Q;
multiset<int> p, gaps;

void add(int x){
    auto it = p.insert(x);
    auto it1 = it, it2 = it;
    it1--;
    it2++;
    int n = *it, n1 = *it1, n2 = *it2;
    if((int)p.size() == 1){}
    else if(it == p.begin()){
        gaps.insert(n2 - n);
    }else if(it2 == p.end()){
        gaps.insert(n - n1);
    }else{
        gaps.erase(gaps.find(n2 - n1));
        gaps.insert(n2 - n);
        gaps.insert(n - n1);
    }
}

void remove(int x){
    auto it = p.find(x);
    auto it1 = it, it2 = it;
    it1--;
    it2++;
    int n = *it, n1 = *it1, n2 = *it2;
    if((int)p.size() == 1){}
    else if(it == p.begin()){
        gaps.erase(gaps.find(n2 - n));
    }else if(it2 == p.end()){
        gaps.erase(gaps.find(n - n1));
    }else{
        gaps.insert(n2 - n1);
        gaps.erase(gaps.find(n2 - n));
        gaps.erase(gaps.find(n - n1));
    }
    p.erase(it);
}

void print(){
    if((int)p.size() == 0){
        cout << 0 << endl;
    }else if((int)gaps.size() == 0){
        cout << *p.rbegin() - *p.begin() << endl;
    }else{
        cout << *p.rbegin() - *p.begin() - *gaps.rbegin() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        add(x);
    }
    print();
    for(int i = 0; i < Q; i++){
        int t, x; cin >> t >> x;
        if(t == 0){
            remove(x);
        }else{
            add(x);
        }
        print();
    }
    return 0;
}


