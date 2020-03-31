#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main(){
    int N;
    cin >> N;
    int deg[N];
    fill(deg, deg + N, 0);
    vector<pii> edges;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back(pii(a, b));
        deg[a-1]++;
        deg[b-1]++;
    }
    int mval = 0, midx = 0;
    for(int i = 0; i < N; i++){
        //cout << deg[i] << endl;
        if(deg[i] > mval){
            mval = deg[i];
            midx = i;
        }
    }
    int reserved = 0, notreserved = mval;
    for(int i = 0; i < N-1; i++){
        if(edges[i].first-1 == midx || edges[i].second-1 == midx){
            cout << reserved++ << endl;
        }else{
            cout << notreserved++ << endl;
        }
    }
    return 0;
}
