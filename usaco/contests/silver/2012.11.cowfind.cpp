#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> legpos1;
vector<int> legpos2;

int main(){
    int ret = 0;
    ifstream fin("cowfind.in");
    ofstream fout("cowfind.out");
    string grass;
    fin >> grass;
    for(int i = 1; i < grass.length(); i++){
        char prev = grass[i - 1];
        char curr = grass[i];
        if(curr == prev){
            if(curr == '(')
                legpos1.push_back(i - 1);
            else
                legpos2.push_back(i - 1);
        }
    }
    for(int i : legpos1){
        for(int j : legpos2){
            if(i > j)
                continue;
            ret++;
        }
    }
    fout << ret << endl;
    return 0;
}
