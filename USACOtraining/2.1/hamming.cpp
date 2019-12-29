#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

bool check(vvb hammed, int D, vb test, int B){
    for(vb i : hammed){
        int diff = 0;
        FOR(j, 0, B)
            if(i[j] != test[j])
                diff++;
        if(diff < D)
            return false;
    }
    return true;
}

vb dectobin(int B, int dec){
    int m = pow(2, B - 1);
    vb ret(B, false);
    for(int i = 0; dec > 0; i++){
        ret[i] = dec / m;
        dec %= m;
        m /= 2;
    }
    return ret;
}

int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    int N, B, D; fin >> N >> B >> D;
    int maxN = pow(2, B), success = 0;
    vvb hammed;
    vi ret;
    FOR(i, 0, maxN){
        vb test = dectobin(B, i);
        if(check(hammed, D, test, B)){
            success++;
            if(success > N)
                break;
            ret.push_back(i);
            hammed.push_back(test);
        }
    }
    FOR(i, 0, (int)ret.size() - 1){
        fout << ret[i];
        if((i + 1) % 10 == 0)
            fout << endl;
        else
            fout << " ";
    }
    fout << ret[ret.size() - 1] << endl;
    return 0;
}
