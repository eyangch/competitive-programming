#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int N;
    array<pair<int, int>, 100000> cows;
    fin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        cows[i] = make_pair(a, b);
    }
    sort(cows.begin(), cows.begin() + N);
    bool duplicateStart = false;
    for(int i = 0; i < N - 1; i++){
        if(get<0>(cows[i]) == get<0>(cows[i+1])){
            duplicateStart = true;
            cows[i] = make_pair(-1, -1);
        }
    }
    int largestEndTime = 0;
    int totalTime = 0;
    for(int i = 0; i < N; i++){
        if(get<0>(cows[i]) == -1)
            continue;
        int s = get<0>(cows[i]);
        int e = get<1>(cows[i]);
        if(s <= largestEndTime){
            if(e > largestEndTime){
                totalTime += e - largestEndTime;
                largestEndTime = e;
            }else{
                duplicateStart = true;
                cows[i] = make_pair(-1, -1);
            }
        }else{
            totalTime += e - s;
            largestEndTime = e;
        }
    }
    if(duplicateStart){
        fout << totalTime << endl;
        return 0;
    }
    largestEndTime = 0;
    int minIndividualTime = 1000000000;
    bool ree = false;
    for(int i = 0; i < N - 1; i++){
        int s = get<0>(cows[i]);
        int e = get<1>(cows[i]);
        if(s >= largestEndTime){
            if(e <= get<0>(cows[i+1]))
                minIndividualTime = min(e - s, minIndividualTime);
            else
                minIndividualTime = min(get<0>(cows[i+1]) - s, minIndividualTime);
        }else{
            if(e <= get<0>(cows[i+1]))
                minIndividualTime = min(e - largestEndTime, minIndividualTime);
            else
                minIndividualTime = min(get<0>(cows[i+1]) - largestEndTime, minIndividualTime);
        }
        if(minIndividualTime < 0 && !ree)
            ree = true;
        largestEndTime = e;
    }
    fout << totalTime - minIndividualTime << endl;
    return 0;
}
