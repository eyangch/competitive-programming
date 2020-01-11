#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int N, c[100000], last = 1, maxC = 0;
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> c[i];
    sort(begin(c), begin(c) + N);
    for(int i = 0; i < N; i++){
        bool gap1 = true;
        while(N - (last - i - 1) >= c[last] - c[i] && last < N){
            if(c[last] - c[last-1] > 1)
                gap1 = false;
            last++;
        }
        if(last - i > maxC && (!gap1 || (i != 0 && last != N)))
            maxC = last - i;
    }
    int minimum = N - maxC, maximum = c[N-1] - c[0] - min(c[1] - c[0], c[N-1] - c[N-2]) - N + 2;
    fout << min(minimum, maximum) << endl << maximum << endl;
    return 0;
}
