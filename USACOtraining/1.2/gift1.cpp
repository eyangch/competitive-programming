#include <bits/stdc++.h>

using namespace std;

int NP;
array<string, 10> people;
array<int, 10> money;

int getPerson(string x){
    int ret;
    for(int i = 0; i < 10; i++){
        if(x == people[i]){
            ret = i;
            break;
        }
    }
    return ret;
}

int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    fin >> NP;
    for(int i = 0; i < NP; i++)
        fin >> people[i];
    for(int i = 0; i < NP; i++){
        string personS;
        fin >> personS;
        int person = getPerson(personS);
        int initmoney;
        fin >> initmoney;
        money[person] += -initmoney;
        int split;
        fin >> split;
        if(split != 0){
            int mpp = initmoney/split;
            money[person] += (initmoney - mpp * split);
            for(int j = 0; j < split; j++){
                string dpersonS;
                fin >> dpersonS;
                int dperson = getPerson(dpersonS);
                money[dperson] += mpp;
            }
        }
    }
    for(int i = 0; i < NP; i++)
        fout << people[i] << " " << money[i] << endl;
    return 0;
}
