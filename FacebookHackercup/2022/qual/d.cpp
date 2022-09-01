#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct custom_hash2 {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<int, int> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
};

int T, N, M, Q;
unordered_map<int, int, custom_hash> G[200000];
unordered_map<pair<int, int>, int, custom_hash2> qs;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	cerr << "total tc: " << T << endl; cerr.flush();
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N >> M >> Q;
		cerr << "start " << tc << " " << N << " " << M << " " << Q << endl; cerr.flush();
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		qs.clear();
		for(int i = 0; i < M; i++){
			int a, b, c; eat >> a >> b >> c;
			a--, b--;
			G[a][b] = c;
			G[b][a] = c;
		}
		for(int i = 0; i < Q; i++){
			int X, Y; eat >> X >> Y;
			X--, Y--;
			if(G[X].size() == G[Y].size()){
				if(X > Y) swap(X, Y);
			}else if(G[X].size() > G[Y].size()){
				swap(X, Y);
			}
			auto it = qs.find({X, Y});
			if(it != qs.end()){
				moo << it->second << ' ';
				continue;
			}
			int ans = 0;
			for(pair<int, int> j : G[X]){
				int c = j.first;
				int cap = j.second;
				if(c == Y){
					ans += cap * 2;
					continue;
				}
				auto it = G[c].find(Y);
				if(it == G[c].end()) continue;
				cap = min(cap, it->second);
				ans += cap;
			}
			moo << ans << ' ';
			qs[{X, Y}] = ans;
		}
		moo << endl;
		cerr << "end " << tc << endl; cerr.flush();
	}
}