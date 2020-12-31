#include <bits/stdc++.h>

using namespace std;

int N;
double p[1000000];

int32_t main(){
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf", &p[i]);
        p[i] /= 1e6;
    }
    double prob = 0;
    int r = 0;
    double csum = p[0]/(1-p[0]);
    double cz = (1-p[0]);
    for(int l = 0; l < N; l++){
        while(r < N-1){
            double nxtsum = csum + (p[r+1]/(1-p[r+1]));
            double nxtz = cz * (1-p[r+1]);
            if(cz*csum > nxtsum * nxtz){
                break;
            }
            r++;
            csum = nxtsum;
            cz = nxtz;
        }
        prob = max(prob, cz*csum);
        csum -= (p[l]/(1-p[l]));
        cz /= (1-p[l]);
    }
    printf("%d\n", (int)(prob * 1e6));
}
