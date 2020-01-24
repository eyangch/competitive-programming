#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, ret = 0, nascent = 0;
    cin >> N;
    vector<int> s[N];
    ll minV[N], maxV[N];
    bool hasAscent[N];
    for(int i = 0; i < N; i++){
        ll a, small = INT_MAX, big = INT_MIN;
        bool ascent = false;
        cin >> a;
        for(int j = 0; j < a; j++){
            ll x;
            cin >> x;
            s[i].push_back(x);
            small = min(small, x);
            big = max(big, x);
            if(x > small){
                ascent = true;
            }
        }
        if(ascent){
            nascent++;
            maxV[i] = INT_MIN;
        }else{
            minV[i] = small;
            maxV[i] = big;
        }
        hasAscent[i] = ascent;
    }
    sort(maxV, maxV + N);
    for(int i = 0; i < N; i++){
        if(hasAscent[i]){
            ret += N;
        }else{
            //cout << "i: " << i << "ret " << ret << endl;
            ret += (maxV + N) - upper_bound(maxV, maxV + N, minV[i]) + nascent;
            //cout << "i: " << i << "ret " << ret << endl;
        }
    }
    //cout << *upper_bound(maxV, maxV + N, minV[1]) << endl;
    cout << ret << endl;
    return 0;
}
