#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

int main(){
    ifstream fin("rental.in");
    ofstream fout("rental.out");
    long long ret = 0;
    int N, M, R;
    fin >> N >> M >> R;
    array<int, 100000> milkval = {}, rentprice = {};
    array<long long, 100000> earnmilk = {}, earnrent = {};
    array<pair<int, int>, 100000> milkprice;
    fill(milkprice.begin(), milkprice.end(), make_pair(0, 0));
    for(int i = 0; i < N; i++)
        fin >> milkval[i];
    for(int i = 0; i < M; i++)
        fin >> get<1>(milkprice[i]) >> get<0>(milkprice[i]);
    for(int i = 0; i < R; i++)
        fin >> rentprice[i];
    sort(milkval.begin(), milkval.begin() + N);
    sort(milkprice.begin(), milkprice.begin() + M, greater<pair<int, int>>()); // sort by price
    sort(rentprice.begin(), rentprice.begin() + R, greater<int>());
    for(int i = 0; i < N; i++)
        earnrent[i] = rentprice[i];
    int store = 0;
    for(int i = N-1; i >= 0; i--){
        while(store < M && milkval[i] >= get<1>(milkprice[store]) && get<0>(milkprice[store]) != 0){
            earnmilk[i] += get<0>(milkprice[store]) * get<1>(milkprice[store]);
            milkval[i] -= get<1>(milkprice[store]);
            store++;
        }
        if(store < M){
            earnmilk[i] += get<0>(milkprice[store]) * milkval[i];
            get<1>(milkprice[store]) -= milkval[i];
        }
        ret += max(earnrent[i], earnmilk[i]);
    }
    fout << ret << endl;
    return 0;
}
