#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;

void mllAdd(mll &spicy, int add){
    if(spicy.find(add) == spicy.end()){
        spicy.insert(pll(add, 1));
    }else{
        spicy[add]++;
    }
}

void mllRemove(mll &spicy, int rm){
    spicy[rm]--;
    if(spicy[rm] == 0){
        spicy.erase(rm);
    }
}

int main(){
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    ll N, M; cin >> N >> M;
    pll food[100000];
    for(int i = 0; i < N; i++){
        cin >> food[i].first >> food[i].second;
    }
    mll spicy;
    ll taste = 0, start, beginning = 0;
    for(int i = 0; i < N && taste < M; i++){
        taste += food[i].first;
        mllAdd(spicy, food[i].second);
        start = i;
    }
    mll::iterator last = spicy.end();
    ll minspicy = (--last) -> first;
    taste -= food[beginning].first;
    mllRemove(spicy, food[beginning].second);
    beginning++;
    for(int i = start + 1; i < N; i++){
        taste += food[i].first;
        mllAdd(spicy, food[i].second);
        if(taste >= M){
            last = spicy.end();
            minspicy = min(minspicy, (--last) -> first);
        }
        while(taste >= M){
            taste -= food[beginning].first;
            mllRemove(spicy, food[beginning].second);
            beginning++;
        }
    }
    cout << minspicy << endl;
    return 0;
}
