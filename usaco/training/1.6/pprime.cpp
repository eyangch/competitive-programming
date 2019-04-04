/*
ID: sireric1
PROG: pprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ans;

void solve(int l, int l1, int num, int bsq){
	if(l1 > l){
		bool isGood = true;
		for(int i = 2; i < sqrt(num); i++){
			if(num % i == 0){
				isGood = false;
				break;
			}
		}
		if(isGood)
			ans.push_back(num);
	}else{
		for(int i = 0; i < 10; i++){
			if(i == 0 && l1 == l)
				continue;
			num += i * (pow(10, l1));
			cout << num << endl;
			solve(l, l1 + 1, num, bsq);
			num -= i * (pow(10, l1));
		}
	}
}

int main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int a, b;
	fin >> a >> b;
	int bsqrt = sqrt(b);
	for(int i = 1; i <= floor(log10(b)) + 1; i++){
		solve(i, 1, 0, bsqrt);
	}
	for(unsigned int i = 0; i < ans.size(); i++)
		fout << ans[i] << endl;
	return 0;
}
