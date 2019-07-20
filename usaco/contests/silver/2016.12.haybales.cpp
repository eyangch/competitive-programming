#include <bits/stdc++.h>

using namespace std;

int binSch(int start, int endd, int bales[100000], int N){
	if(start > bales[N-1] || endd < bales[0])
		return 0;
	int bottom = 0;
	int top = N-1;
	int mid = (top + bottom)/2;
	int bTarget = 0;
	while(top > bottom){
		if(bales[mid] >= start)
			top = mid - 1;
		else
			bottom = mid + 1;
		mid = (top + bottom)/2;
	}
	if(bales[mid] < start)
        mid++;
	bTarget = mid;
	bottom = 0;
	top = N-1;
	mid = (top + bottom)/2;
	while(top > bottom){
		if(bales[mid] <= endd)
			bottom = mid + 1;
		else
			top = mid - 1;
		mid = (top + bottom)/2;
	}
	if(bales[mid] > endd)
        mid--;
	return (mid - bTarget) + 1;
}

int main(){
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");
	int N, Q;
	int bales[100000];
	pair<int, int> queries[100000];
	fin >> N >> Q;
	for(int i = 0; i < N; i++)
		fin >> bales[i];
	for(int i = 0; i < Q; i++)
		fin >> get<0>(queries[i]) >> get<1>(queries[i]);
	sort(bales, bales + N);
	for(int i = 0; i < Q; i++)
		fout << binSch(get<0>(queries[i]), get<1>(queries[i]), bales, N) << endl;
}
