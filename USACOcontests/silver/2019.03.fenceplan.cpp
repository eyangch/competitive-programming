#include <bits/stdc++.h>

using namespace std;

bool been[100000];

void r(int N, int pos, vector<int> ct[100000], vector<int> &x){
    if(been[pos]) return;
    been[pos] = true;
    x.push_back(pos);
    for(unsigned int i = 0; i < ct[pos].size(); i++)
        r(N, ct[pos][i], ct, x);
}

int main(){
	ifstream fin("fenceplan.in");
	ofstream fout("fenceplan.out");
	int N, M, cpos[100000][2], ret = INT_MAX;
    vector<int> ct[100000];
	fin >> N >> M;
	fill(been, been + N, false);
	for(int i = 0; i < N; i++)
        fin >> cpos[i][0] >> cpos[i][1];
    for(int i = 0; i < M; i++){
        int a, b;
        fin >> a >> b;
        ct[a-1].push_back(b-1);
        ct[b-1].push_back(a-1);
    }
    for(int i = 0; i < N; i++){
        if(been[i]) continue;
        vector<int> x;
        r(N, i, ct, x);
        int xmin = INT_MAX, ymin = INT_MAX, xmax = 0, ymax = 0;
        for(int i : x){
            xmin = min(xmin, cpos[i][0]);
            ymin = min(ymin, cpos[i][1]);
            xmax = max(xmax, cpos[i][0]);
            ymax = max(ymax, cpos[i][1]);
        }
        ret = min(ret, 2 * (xmax - xmin + ymax - ymin));
    }
    fout << ret << endl;
	return 0;
}
