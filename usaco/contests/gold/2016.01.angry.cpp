#include <bits/stdc++.h>

using namespace std;

int binSrch(int N, int bales[50000], int t){
    int bot = 0;
    int top = N-1;
    int mid = (bot + top) / 2;
    while(bot < top){
        if(bales[mid] > t)
            top = mid - 1;
        else
            bot = mid + 1;
        mid = (bot + top) / 2;
    }
    if(bales[mid] < t) mid++;
    return mid;
}

double binSrch2(int N, int rLidx, int rL[50000], int rR[50000], int bales[50000]){
    int bot = rLidx + 1;
    int top = N-1;
    int mid = (bot + top) / 2;
    double dis = (bales[mid] - bales[rLidx]) / 2.0;
    double pwr = max(rL[rLidx] + 1, rR[mid] + 1);
    double reqpwr = max(dis, pwr);
    while(bot <= top){
        dis = (bales[mid] - bales[rLidx]) / 2.0;
        pwr = max(rL[rLidx] + 1, rR[mid] + 1);
        if(dis > pwr)
            top = mid - 1;
        else
            bot = mid + 1;
        mid = (bot + top) / 2;
        reqpwr = min(reqpwr, max(dis, pwr));
    }
    if(dis > pwr){
        mid--;
        dis = (bales[mid] - bales[rLidx]) / 2.0;
        pwr = max(rL[rLidx] + 1, rR[mid] + 1);
        return min(reqpwr, max(dis, pwr));
    }
    if(dis < pwr){
        mid++;
        dis = (bales[mid] - bales[rLidx]) / 2.0;
        pwr = max(rL[rLidx] + 1, rR[mid] + 1);
        return min(reqpwr, max(dis, pwr));
    }
    return reqpwr;
}

int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N, bales[50000], diff[49999], rL[50000], rR[50000];
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> bales[i];
    sort(bales, bales + N);
    for(int i = 0; i < N - 1; i++)
        diff[i] = bales[i + 1] - bales[i]; // get Diff O(N)
    rL[0] = 0;
    for(int i = 1; i < N; i++){
        rL[i] = max(rL[i-1] + 1, diff[i-1]);
        rL[i] = min(rL[i], max(rL[binSrch(N, bales, bales[i] - rL[i])] + 1, diff[i-1])); // go from left to right calculate what r O(N logN)
    }
    rR[N-1] = 0;
    for(int i = N-2; i >= 0; i--){
        rR[i] = max(rR[i+1] + 1, diff[i]);
        rR[i] = min(rR[i], max(rR[binSrch(N, bales, bales[i] + rR[i]) - 1] + 1, diff[i])); // go from left to right calculate what r O(N logN)
    }
    double ret = DBL_MAX;
    for(int i = 0; i < N - 1; i++)
        ret = min(ret, binSrch2(N, i, rL, rR, bales));
    fout << fixed << setprecision(1) << ret << endl;
    return 0;
}
