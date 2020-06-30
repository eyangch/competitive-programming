#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    int N;
    array<int, 100000> w;
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> w[i];
    sort(w.begin(), w.begin() + N, greater<int>());
    int i;
    for(i = 0; i < N; i++)
        if(w[i] < i)
            break;
    fout << i << endl;
    return 0;
}
