#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream fin("cowcode.in");
	ofstream fout("cowcode.out");
	string s;
	long long N, slen;
	fin >> s >> N;
	slen = s.length();
	while(N > slen){
		long long ft = ceil(log2(ceil((N/(double)slen))));
		if(N % (slen * (int)pow(2, ft-1)) == 1)
			N = slen * (long long)pow(2, ft-1);
		else
			N -= slen * (long long)pow(2, ft-1) + 1;
	}
	fout << s[N-1] << endl;
}
