#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define double long double

using namespace std;

struct dat{
    double c, m, p, d, prob;
};

int T;
double c, m, p, v;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    moo << fixed << setprecision(15);
    while(T--){
        eat >> c >> m >> p >> v;
        queue<dat> q;
        q.push({c, m, p, 1, 1.0});
        double ans = 0;
        while(!q.empty()){
            double cc = q.front().c, cm = q.front().m, cp = q.front().p, cd = q.front().d, cprob = q.front().prob;
            q.pop();
            ans += cd * cprob * cp;
            if(cc > 1e-7){
                dat chc = {cc, cm, cp, cd+1, cprob * cc};
                if(cc > v){
                    chc.c -= v;
                    if(chc.m > 1e-7){
                        chc.m += v/2;
                        chc.p += v/2;
                    }else{
                        chc.p += v;
                    }
                }else{
                    if(chc.m > 1e-7){
                        chc.m += chc.c/2;
                        chc.p += chc.c/2;
                    }else{
                        chc.p += chc.c;
                    }
                    chc.c = 0;
                }
                q.push(chc);
            }
            if(cm > 1e-7){
                dat chm = {cc, cm, cp, cd+1, cprob * cm};
                if(cm > v){
                    chm.m -= v;
                    if(chm.c > 1e-7){
                        chm.c += v/2;
                        chm.p += v/2;
                    }else{
                        chm.p += v;
                    }
                }else{
                    if(chm.c > 1e-7){
                        chm.c += chm.m/2;
                        chm.p += chm.m/2;
                    }else{
                        chm.p += chm.m;
                    }
                    chm.m = 0;
                }
                q.push(chm);
            }
        }
        moo << ans << endl;
    }
}
