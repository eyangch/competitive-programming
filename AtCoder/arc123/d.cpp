#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[200000], B[200000], C[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	int sBp = 0, sBn = 0, sCp = 0, sCn = 0;
	int nBp = 0, nBn = 0, nCp = 0, nCn = 0;
	int cB = 0, cC = 0;
	for(int i = 0; i < N; i++){
		int d = A[i] - cB + cC;
		if(d >= 0){
			cB += d;
		}else{
			cC -= d;
		}
		B[i] = cB;
		C[i] = cC;
		if(cB >= 0){
			sBp += cB;
			nBp++;
		}else{
			sBn += cB;
			nBn++;
		}
		if(cC >= 0){
			sCp += cC;
			nCp++;
		}else{
			sCn += cC;
			nCn++;
		}
	}
	int ans = LLONG_MAX;
	int ptrB = 0, ptrC = 0;
	int pv = 0;
	while(ptrB < N || ptrC < N){
		int bv = LLONG_MAX, cv = LLONG_MAX;
		if(ptrB < N) bv = B[ptrB];
		if(ptrC < N) cv = C[ptrC];
		if(bv < cv){
			if(bv >= 0){
				int d = bv - pv;
				pv = bv;
				sBp -= nBp * d;
				sCp -= nCp * d;
				sBn += nBn * d;
				sCn += nCn * d;
				nBp--;
				nBn++;
			}
			ptrB++;
		}else{
			if(cv >= 0){
				int d = cv - pv;
				pv = cv;
				sBp -= nBp * d;
				sCp -= nCp * d;
				sBn += nBn * d;
				sCn += nCn * d;
				nCp--;
				nCn++;
			}
			ptrC++;
		}
		int cur = sBp + sCp + sBn + sCn;
		ans = min(ans, cur);
	}
	moo << ans << endl;
}