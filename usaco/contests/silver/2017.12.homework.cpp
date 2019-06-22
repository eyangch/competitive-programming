#include <iostream>
#include <fstream>
#include <array>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int N;
array<int, 100000> scores;
array<int, 100000> mins;

int main(){
	ifstream fin("homework.in");
	ofstream fout("homework.out");
	fin >> N;
	for(int i = 0; i < N; i++)
		fin >> scores[i];
	array<int, 10000>::iterator it = min_element(scores.begin(), scores.begin() + N);
	int dis = distance(scores.begin(), it);
	fill(mins.begin(), mins.begin() + dis + 1, *it);
	while(it != scores.begin() + N){
		int dis2 = dis;
		it = min_element(scores.begin() + dis2 + 1, scores.begin() + N);
		dis = distance(scores.begin(), it);
		fill(mins.begin() + dis2 + 1, mins.begin() + dis + 1, *it);
	}
	int add = accumulate(scores.begin() + 1, scores.begin() + N, 0);
	double m = 0;
	vector<int> hs;
    for(int i = 1; i < N - 1; i++){
        double ta = add;
        ta -= mins[i];
        ta /= N - i - 1;
        if(ta > m){
            m = ta;
            hs.clear();
        }
        if(ta == m)
            hs.push_back(i);
        add -= scores[i];
    }
    for(int i : hs)
        fout << i << endl;
	return 0;
}
