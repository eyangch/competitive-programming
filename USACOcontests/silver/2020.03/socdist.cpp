#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

bool works(ll N, ll M, pll grass[100000], ll dist){
    ll pos = grass[0].first;
    ll curr = 0;
    for(int i = 0; i < N; i++){
        if(pos > grass[M-1].second){
            return false;
        }
        ll low = lower_bound(grass + curr, grass + M, pll(pos, 0)) - grass;
        if(low > 0 && grass[low - 1].second >= pos){
            low--;
        }else if(grass[low].first > curr && grass[low - 1].second < pos){
            pos = grass[low].first;
        }
        curr = low;
        pos += dist;
    }
    return true;
}

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    ll N, M;
    cin >> N >> M;
    pll grass[100000];
    for(int i = 0; i < M; i++){
        cin >> grass[i].first >> grass[i].second;
    }
    sort(grass, grass + M);
    ll h = 1e18;
    ll l = 0;
    ll m = (h + l) / 2;
    while(h > l + 1){
        m = (h + l) / 2;
        bool doeswork = works(N, M, grass, m);
        if(!doeswork){
            h = m - 1;
        }
        if(doeswork){
            l = m;
        }
    }
    while(!works(N, M, grass, m)){
        m--;
    }
    while(works(N, M, grass, m)){
        m++;
    }
    cout << m-1 << endl;
    return 0;
}
