#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

struct segt{
    int a[200000], l[800001], r[800001], mw[800001], lw[800001], rw[800001], cl, cr, f;
    void init(int i, int l, int r){
        this->l[i] = l, this->r[i] = r;
        if(l == r){
            lw[i] = rw[i] = 1;
            return;
        }
        init(i*2, l, (l+r)/2);
        init(i*2+1, (l+r)/2+1, r);
        lw[i] = rw[i] = lw[i*2] + lw[i*2+1];
    }
    void upd(int i, int d, int v){
        if(r[i] < d || l[i] > d) return;
        if(l[i] == r[i]){
            a[l[i]] = v;
            return;
        }
        upd(i*2, d, v);
        upd(i*2+1, d, v);
        mw[i] = mw[i*2] + mw[i*2+1];
        bool f1 = (lw[i*2] == r[i*2] - l[i*2] + 1), f2 = (lw[i*2+1] == r[i*2+1] - l[i*2+1] + 1);
        if(a[r[i*2]] <= a[l[i*2+1]]){
            if(f1 && f2){
                lw[i] = rw[i] = lw[i*2] + lw[i*2+1];
            }else if(f1 && !f2){
                lw[i] = lw[i*2] + lw[i*2+1];
                rw[i] = rw[i*2+1];
            }else if(!f1 && f2){
                lw[i] = lw[i*2];
                rw[i] = rw[i*2] + rw[i*2+1];
            }else{
                lw[i] = lw[i*2];
                rw[i] = rw[i*2+1];
                mw[i] += (rw[i*2] + lw[i*2+1]) * (rw[i*2] + lw[i*2+1] + 1) / 2;
            }
        }else{
            lw[i] = lw[i*2];
            rw[i] = rw[i*2+1];
            if(!f2){
                mw[i] += lw[i*2+1] * (lw[i*2+1]+1) / 2;
            }
            if(!f1){
                mw[i] += rw[i*2] * (rw[i*2]+1) / 2;
            }
        }
    }
    int qry(int i, int xl, int xr){
        if(r[i] < xl || l[i] > xr){
            cl = cr = f = 0;
            return -1;
        }
        if(l[i] == r[i]){
            cl = cr = lw[i];
            f = true;
            return 0;
        }if(l[i] >= xl && r[i] <= xr){
            cl = lw[i], cr = rw[i];
            if(lw[i] == r[i] - l[i] + 1) f = true;
            else f = false;
            return mw[i];
        }else{
            int a1 = qry(i*2, xl, xr);
            int l1 = cl, r1 = cr;
            bool f1 = f;
            int a2 = qry(i*2+1, xl, xr);
            int l2 = cl, r2 = cr;
            bool f2 = f;
            //moo << i << " " << l[i] << " " << r[i] << " " << a1 << " " << a2 << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if(a1 == -1){
                return a2;
            }
            if(a2 == -1){
                cl = l1, cr = r1, f = f1;
                return a1;
            }
            int mid1 = r1, mid2 = l2;
            //moo << a[r[i*2]] << " " << a[l[i*2+1]] << endl;
            if(a[r[i*2]] <= a[l[i*2+1]]){
                mid1 = r1 + l2, mid2 = 0;
            }else{
                f = false;
                cl = l1, cr = r2;
                int ret = a1 + a2;
                if(!f1){
                    ret += (r1 * (r1 + 1) / 2);
                }
                if(!f2){
                    ret += (l2 * (l2 + 1) / 2);
                }
                //moo << "BOO" << endl;
                return ret;
            }
            if(f1 && f2){
                f = true;
                cl = cr = l1 + l2;
                return 0;
            }if(f1 && !f2){
                f = false;
                cl = l1 + l2;
                cr = r2;
                return a1 + a2;
            }if(!f1 && f2){
                f = false;
                cl = l1;
                cr = r1 + r2;
                return a1 + a2;
            }
            f = false;
            cl = l1, cr = r2;
            return a1 + a2 + (mid1 * (mid1+1) / 2) + (mid2 * (mid2+1) / 2);
        }
    }
};

int N, Q;
segt s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> Q;
    s.init(1, 0, N-1);
    for(int i = 0; i < N; i++){
        int x; eat >> x;
        s.upd(1, i, x);
    }
    for(int i = 0; i < Q; i++){
        int t, x, y; eat >> t >> x >> y;
        if(t == 1){
            s.upd(1, x-1, y);
        }else{
            int ans = s.qry(1, x-1, y-1);
            if(s.f){
                moo << (s.cl * (s.cl+1) / 2) << endl;
                continue;
            }
            ans += (s.cl * (s.cl + 1) / 2) + (s.cr * (s.cr + 1) / 2);
            moo << ans << endl;
        }
    }
}
