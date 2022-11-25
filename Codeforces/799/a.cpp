#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, T, K, D;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> T >> K >> D;
	/*int t_one = 1e15;
	int t_two = 1e15;
	int bakes = N / K + (N % K > 0);
	t_one = bakes * T;
	int o_make = D / T + (D % T > 0);
	int t_end = o_make * T;
	int c_left = N - o_make;
	if(c_left > 0){
		c_left 
	}*/
	int bakes = N / K + (N % K > 0);
	int last_ins = (bakes - 1 ) * T;
	if(D < last_ins){
		moo << "YES" << endl;
	}else{
		moo << "NO" << endl;
	}
}