#include <iostream>
#include <fstream>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

int main(){
	ifstream fin("gymnastics.in");
	ofstream fout("gymnastics.out");
	int order[10][20], ret = 0;
	int K, N; fin >> K >> N;
	FOR(i, 0, K){
		FOR(j, 0, N){
			fin >> order[i][j];
		}
	}
	FOR(i, 0, N-1){
		int a = order[0][i];
		FOR(j, i+1, N){
			int b = order[0][j];
			FOR(l, 1, K){
				bool found = false, good = true;
				FOR(m, 0, N){
					if(order[l][m] == a){
						found = true;
					}
					if(!found && order[l][m] == b){
						good = false;
						break;
					}
				}
				if(!good){
					ret--;
					break;
				}
			}
			ret++;
		}
	}
	fout << ret << endl;
} 
