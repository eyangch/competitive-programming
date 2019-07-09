#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <utility>

using namespace std;

int main(){
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    int N, B;
    array<int, 250> sDepth;
    array<pair<int, int>, 250> boots;
    array<array<int, 250>, 250> bkSteps;
    fin >> N >> B;
    for(int i = 0; i < N; i++)
        fin >> sDepth[i];
    for(int i = 0; i < B; i++)
        fin >> get<0>(boots[i]) >> get<1>(boots[i]);
    for(int i = 0; i < B; i++){
        int mDepth = get<0>(boots[i]);
        int mStep = get<1>(boots[i]);
        int prevStep = N-1;
        for(int j = N-1; j >= 0; j--){
            if(sDepth[j] > mDepth){
                bkSteps[i][j] = -1; // Unable to step
                continue;
            }
            if(prevStep - j <= mStep)
                bkSteps[i][prevStep] = j;
            else
                bkSteps[i][prevStep] = -1; // New step cycle
            prevStep = j;
        }
    }
    int cPos = 0;
    int bootN = 0;
    int ret = 0;
    while(cPos < N-1){
        int begPos = N-1;
        bool finding = false;
        for(int i = N-1; i >= cPos || sDepth[i] > get<0>(boots[bootN]);){
            if(bkSteps[bootN][i] == -1){
                i--;
                finding = true;
                begPos = cPos;
                continue;
            }
            if(finding){
                finding = false;
                begPos = i;
            }
            i = bkSteps[bootN][i];
            if(i == 0)
                break;
        }
        cPos = begPos;
        bootN++;
        ret++;
    }
    fout << ret - 1 << endl;
    return 0;
}
