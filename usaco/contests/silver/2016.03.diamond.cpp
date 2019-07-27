#include <bits/stdc++.h>

using namespace std;

int binSrch(int N, int d[], int t){
    int bot = 0;
    int top = N-1;
    int mid = (bot + top) / 2;
    while(bot < top){
        if(d[mid] > t)
            top = mid - 1;
        else
            bot = mid + 1;
        mid = (bot + top) / 2;
    }
    if(d[mid] > t) mid--;
    return mid;
}

int main(){
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int N, K, d[50000], nums[50000], maxes[50000], ret = 0;
    fin >> N >> K;
    for(int i = 0; i < N; i++)
        fin >> d[i];
    sort(d, d + N);
    for(int i = 0; i < N; i++)
        nums[i] = binSrch(N, d, d[i] + K) - i;
    int maxIdx = distance(nums, max_element(nums, nums + N));
    fill(maxes, maxes + maxIdx, maxIdx);
    while(maxIdx < N){
        int newMaxIdx = distance(nums, max_element(nums + maxIdx + 1, nums + N));
        fill(maxes + maxIdx, maxes + newMaxIdx, newMaxIdx);
        maxIdx = newMaxIdx;
    }
    for(int i = 0; i < N - nums[N-1]; i++)
        ret = max(ret, nums[i] + nums[maxes[nums[i] + i]]);
    fout << ret + 2 << endl;
    return 0;
}
