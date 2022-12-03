#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct op{
	char r1, r2, r3;
};

int X, Y;
vector<op> res;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> X >> Y;
	char rX = 'A', rY = 'B';
	if(X > Y){
		swap(X, Y);
		swap(rX, rY);
	}
	for(int i = 0; i < 32; i++){
		if((X >> i) == 0) break;
		if((X >> i) & 1){
			res.push_back({rY, 'C', 'C'});
		}
		res.push_back({rY, rY, rY});
	}
	moo << res.size() << endl;
	for(op i : res){
		moo << i.r1 << ' ' << i.r2 << ' ' << i.r3 << endl;
	}
	moo << 'C' << endl;
}