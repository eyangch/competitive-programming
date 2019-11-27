#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct fraction{
    int n;
    int d;
};

bool cmpFrac(fraction x, fraction y){
    return (x.n/(float)x.d) < (y.n/(float)y.d);
}

bool isRelPrime(int x, int y){
    int xn = sqrt(x);
    int yn = sqrt(y);
    vector<int> xl, yl;
    bool yesx = false;
    bool yesy = false;
    for(int i = 1; i <= xn; i++){
        if(x % i == 0){
            xl.push_back(i);
            xl.push_back(x/i);
            yesx = true;
        }
    }
    for(int i = 1; i <= yn; i++){
        if(y % i == 0){
            yl.push_back(i);
            yl.push_back(y/i);
            yesy = true;
        }
    }

    if((!yesx || !yesy) && y != 1){
        return false;
    }

    for(int i = 0; i < xl.size(); i++){
        for(int j = 0; j < yl.size(); j++){
            if(xl[i] == yl[j] && (xl[i] != 1 || x == y || x == 0) && x != 1 && y != 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ifstream fin ("frac1.in");
    ofstream fout ("frac1.out");
    int N;
    vector<fraction> fracs;
    fin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(isRelPrime(j, i)){
                fraction tmp;
                tmp.d = i;
                tmp.n = j;
                fracs.push_back(tmp);
            }
        }
    }
    sort(fracs.begin(), fracs.end(), cmpFrac);
    for(int i = 0; i < fracs.size(); i++){
            fout << fracs[i].n << "/" << fracs[i].d << endl;
    }
    return 0;
}
