#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N; fin >> N;
    int months[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, day = 2, week[7];
    fill(week, week + 7, 0);
    day += 12;
    day %= 7;
    week[day]++;
    FOR(i, 1900, 1900 + N){
        FOR(j, 0, 12){
            if(months[j] == -1){
                if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
                    day += 29;
                else
                    day += 28;
            }else
                day += months[j];
            day %= 7;
            week[day]++;
        }
    }
    week[day]--;
    FOR(i, 0, 6)
        fout << week[i] << " ";
    fout << week[6] << endl;
    return 0;
}
