#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, D1, D2, D3;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> D1 >> D2 >> D3;
		if((D1 + D2 + D3) % 2 == 1){
			moo << "NO" << endl;
			continue;
		}
		int a = (D1 - D2 + D3) / 2;
		int b = (D2 - D3 + D1) / 2;
		int c = (D3 - D1 + D2) / 2;
		if(a < 0 || b < 0 || c < 0){
			moo << "NO" << endl;
			continue;
		}
		if(a + b + c + 1 > N){
			moo << "NO" << endl;
			continue;
		}
		int z = (a == 0) + (b == 0) + (c == 0);
		if(z > 1){
			moo << "NO" << endl;
			continue;
		}
		int center = 4;
		if(a == 0) center = 1;
		if(b == 0) center = 2;
		if(c == 0) center = 3;
		int node = center;
		int nnode = 5 - z;
		vector<pair<int, int>> e;
		if(a != 0){
			for(int i = 0; i < a-1; i++){
				e.push_back({node, nnode});
				node = nnode;
				nnode++;
			}
			e.push_back({node, 1});
		}
		node = nnode-1;
		//moo << "NODE: " << node << endl;
		nnode = node+1;
		node = center;
		if(b != 0){
			for(int i = 0; i < b-1; i++){
				e.push_back({node, nnode});
				node = nnode;
				nnode++;
			}
			e.push_back({node, 2});
		}
		node = nnode-1;
		//moo << "NODE: " << node << endl;
		nnode = node+1;
		node = center;
		if(c != 0){
			for(int i = 0; i < c-1; i++){
				e.push_back({node, nnode});
				node = nnode;
				nnode++;
			}
			e.push_back({node, 3});
		}
		node = nnode-1;
		if((int)e.size() >= N){
			moo << "NO" << endl;
			continue;
		}
		//moo << "NODE: " << node << endl;
		if((int)e.size() < N-1){
			e.push_back({3, ++node});
		}
		while((int)e.size() < N-1){
			e.push_back({node, node+1});
			node++;
		}
		moo << "YES" << endl;
		for(pair<int, int> ed : e){
			moo << ed.first << ' ' << ed.second << endl;
		}
	}
}