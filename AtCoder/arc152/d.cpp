#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K;
vector<pair<int, int>> E;
bool vis[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	if(N % 2 == 0){
		moo << -1 << endl;
		return 0;
	}
	vis[0] = vis[K] = 1;
	int A = 0, B = K;
	auto adv = [&A, &B](){
		A++, B++;
		if(A == N) A = 0;
		if(B == N) B = 0;
	};
	while(true){
		adv();
		vis[A] = vis[B] = 1;
		E.push_back({0, A});
		E.push_back({K, B});
		if(A == K || B == 0){
			break;
		}
	}
	while(true){
		adv();
		if(!vis[A] && !vis[B]){
			E.push_back({0, A});
			E.push_back({K, B});
			vis[A] = vis[B] = 1;
		}
		if(A == 0) break;
	}
	int fs = 0;
	for(; fs < N; fs++){
		if(!vis[fs]) break;
	}
	for(; fs < N && !vis[fs] && !vis[fs+1]; fs += 2){
		int x = fs, y = fs+1;
		int z = x-K;
		if(z < 0) z += N;
		E.push_back({y, z});
		E.push_back({x, (y+K) % N});
	}
	moo << E.size()/2 << endl;
	for(int i = 0; i < (int)E.size(); i += 2){
		moo << E[i].first << ' ' << E[i].second << endl;
	}
}