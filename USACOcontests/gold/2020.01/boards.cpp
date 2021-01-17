/*
Solution: O(P logP)
Sort springboards by x1 value (decreasing) and another one by x2 value (decreasing)
Iterate through the x2 sorted array and add viable starting points from the x1 array to a strictly increasing map
Query the starting point with greater or equal y value than the current x2 y2 point (dist = x-val + y-val + end dist)
Subtract the current end point distance to start from that value = d2e
Get minimum (d2e + x1 + x2) throughout all points.
*/

#include <bits/stdc++.h>

using namespace std;

struct board{
    int x, y, x2, y2, i;
};

struct si_map{
    map<int, int> m;
    void insert(int id, int val){
        auto it = m.lower_bound(id);
        if(it != m.end() && it -> second <= val){
            return;
        }
        it = m.lower_bound(id);
        vector<int> rm;
        while(it != m.begin()){
            it--;
            if(it -> second < val) break;
            rm.push_back(it->first);
        }
        for(int i : rm){
            m.erase(i);
        }
        m[id] = val;
    }
    int lb(int id){
        return m.lower_bound(id) -> second;
    }
};

int N, P;
board b[100000], b2[100000];
int di[100000];
si_map m;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    cin >> N >> P;
    for(int i = 0; i < P; i++){
        cin >> b[i].x >> b[i].y >> b[i].x2 >> b[i].y2;
        b[i].i = i;
    }
    copy(b, b+P, b2);
    sort(b, b+P, [](board a, board b){
        if(a.x2 == b.x2) return a.y2 > b.y2;
        return a.x2 > b.x2;
    });
    sort(b2, b2+P, [](board a, board b){
        if(a.x == b.x) return a.y > b.y;
        return a.x > b.x;
    });
    m.insert(N, N+N);
    int ptrb = 0;
    int ans = 2e9;
    for(int i = 0; i < P; i++){
        while(ptrb < P && b2[ptrb].x >= b[i].x2){
            if(b2[ptrb].x == b[i].x2 && b2[ptrb].y < b[i].y2) break;
            int score = b2[ptrb].x + b2[ptrb].y + di[b2[ptrb].i];
            m.insert(b2[ptrb].y, score);
            ptrb++;
        }
        di[b[i].i] = (N - b[i].x2) + (N - b[i].y2);
        int d2e = m.lb(b[i].y2);
        d2e -= b[i].x2 + b[i].y2;
        di[b[i].i] = d2e;
        ans = min(ans, d2e + b[i].x + b[i].y);
    }
    cout << ans << endl;
}
