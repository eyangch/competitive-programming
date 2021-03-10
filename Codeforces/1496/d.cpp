#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, p[100000];
vector<int> lmax;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> p[i];
    }
    lmax.push_back(0);
    for(int i = 1; i < N-1; i++){
        if(p[i] > p[i-1] && p[i] > p[i+1]) lmax.push_back(i);
    }
    lmax.push_back(N-1);
    int mxh = 0;
    bool ok = false;
    for(int i : lmax){
        int l = i, r = i;
        while(l > 0){
            if(p[l-1] < p[l]) l--;
            else break;
        }
        while(r < N-1){
            if(p[r+1] < p[r]) r++;
            else break;
        }
        int ld = i - l;
        int rd = r - i;
        int curh = max(ld, rd);
        if(i == 0){
            if(rd >= mxh){
                mxh = rd;
                ok = false;
            }
            continue;
        }
        if(i == N-1){
            if(ld >= mxh){
                mxh = ld;
                ok = false;
            }
            continue;
        }
        if(curh > mxh){
            mxh = curh;
            if(ld == rd) ok = true;
            else ok = false;
        }else if(curh == mxh) ok = false;
    }
    //moo << mxh << " " << ok << endl;
    moo << (ok && mxh % 2 == 0 ? 1 : 0) << endl;
}
