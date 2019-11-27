#include <bits/stdc++.h>

using namespace std;

int bSrch(int N, int t, vector<int> zeros){
    int l = 0;
    int h = zeros.size() - 1;
    int m = (h + l) / 2;
    while(l <= h){
        if(zeros[m] > t)
            h = m - 1;
        else
            l = m + 1;
        m = (h + l) / 2;
    }
    if(zeros[m] < t && m == (int)zeros.size() - 1)
        return N * 2;
    if(zeros[m] < t && m < (int)zeros.size() - 1)
        m++;
    return m;
}

int main(){
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");
	int N, cards[1000000];
	vector<int> zeros;
	fin >> N;
	for(int i = 0; i < N; i++){
		int tmp;
		fin >> tmp;
		cards[tmp - 1] = 1;
	}
	for(int i = 0; i < N * 2; i++){
        if(cards[i] == 0)
            zeros.push_back(i);
	}
	int win = 0;
	for(int i = 0; i < N * 2; i++){
		if(cards[i] != 1)
			continue;
        int nxtidx = bSrch(N, i, zeros);
        if(nxtidx == N * 2)
			break;
		zeros.erase(zeros.begin() + nxtidx);
		win++;
	}
	fout << win << endl;
}
