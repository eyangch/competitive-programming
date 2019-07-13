#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream fin("hps.in");
	ofstream fout("hps.out");
	int N, ret = 0;
	array<char, 100000> hps;
	array<unordered_map<char, int>, 100000> scores;
	array<char, 3> l {'H', 'P', 'S'};
	fin >> N;
	fin >> hps[0];
	scores[0]['H'] = scores[0]['P'] = scores[0]['S'] = 0;
	scores[0][hps[0]]++;
	for(int i = 1; i < N; i++){
		fin >> hps[i];
		scores[i] = scores[i-1];
		scores[i][hps[i]]++;
	}
	for(int i = 0; i < N; i++){
		unordered_map<char, int> adjscore = scores[N-1];
		int m1 = 0, m2 = 0;
		for(int j : l){
			adjscore[j] -= scores[i][j];
			m1 = max(m1, adjscore[j]);
			m2 = max(m2, scores[i][j]);
		}
		ret = max(ret, m1 + m2);
	}
	fout << ret << endl;
}
