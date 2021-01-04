/*
Solution: O(M logM)
Have two strictly increasing maps to store the required cost for left boundaries and right boundaries.
(Strictly increasing allows retrieval of min cost for a device in O(logN) time)
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

struct si_map{
    map<int, int> mp;

    void insert(int x, int v){
        auto it = mp.lower_bound(x);
        if(it != mp.end() && it->second <= v){
            return;
        }
        if(it != mp.begin()){
            it--;
            vector<int> rm;
            while(true){
                if(it->second < v){
                    break;
                }
                rm.push_back(it->first);
                if(it == mp.begin()){
                    break;
                }
                it--;
            }
            for(int i : rm){
                mp.erase(i);
            }
        }
        mp[x] = v;
    }

    int qry(int x){
        auto it = mp.lower_bound(x);
        if(it == mp.end()){
            return 1e16;
        }
        return it->second;
    }
};

int M, N;
si_map l, r;

int32_t main(){
    cin >> M >> N;
    int ans = 1e16;
    l.insert(1, 0);
    r.insert(-N, 0);
    for(int i = 0; i < M; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int lcost = l.qry(a), rcost = r.qry(-b);
        ans = min(ans, lcost + rcost + d);
        l.insert(c, lcost + d);
        r.insert(-c, rcost + d); 
    }
    cout << (ans == 1e16 ? -1 : ans) << endl;
}
