#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    int N, K, B;
    array<int, 100002> broken;
    fin >> N >> K >> B;
    broken[0] = 0;
    for(int i = 0; i < B; i++)
        fin >> broken[i+1];
    sort(broken.begin()+1, broken.begin() + B + 1);
    broken[B+1] = N;
    int bot = 0, top = 0, ret = B;
    while(top <= B+1){
        int diff = broken[top] - broken[bot];
        if(diff >= K){
            if(bot == 0)
                ret = min(ret, top - bot);
            else
                ret = min(ret, top - bot - 1);
            bot++;
        }else
            top++;
    }
    fout << ret << endl;
    return 0;
}

