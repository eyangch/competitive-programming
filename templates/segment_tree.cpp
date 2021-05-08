#include <bits/stdc++.h>

using namespace std;

struct segt{
    int l, r, mid;
    segt *a, *b;
    int val;
    segt(int vl, int vr, int (&arr)[200000]){
        l = vl, r = vr, mid = (l + r) / 2;
        if(l < r){
            a = new segt(l, mid, arr);
            b = new segt(mid+1, r, arr);
            val = min(a->val, b->val);
        }
        if(l == r){
            val = arr[l];
        }
    }
    void upd(int id, int dv){
        if(l > r || l > id || r < id) return;
        if(l == r){
            val = dv;
        }else{
            a->upd(id, dv);
            b->upd(id, dv);
            val = min(a->val, b->val);
        }
    }
    int qry(int vl, int vr){
        if(l > r || l > vr || r < vl){
            return 1e9;
        }
        if(l >= vl && r <= vr){
            return val;
        }
        return min(a->qry(vl, vr), b->qry(vl, vr));
    }
};
