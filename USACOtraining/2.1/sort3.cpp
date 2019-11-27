#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int N;
int ops = 0;
array<int, 3> hmny;
array<int, 1000> records;
array<bool, 1000> sorted;

int getPmax(int number){
    int x = 0;
    for(int i = 0; i < number; i++)
        x += hmny[i];
    return x;
}

bool isInCorrectPlace(int number, int place){
    int pmax = getPmax(number);
    int pmin = pmax - hmny[number - 1];
    return (place < pmax && place >= pmin);
}

int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    fin >> N;
    for(int i = 0; i < 3; i++)
        hmny[i] = 0;
    for(int i = 0; i < N; i++){
        fin >> records[i];
        sorted[i] = false;
        hmny[records[i] - 1]++;
    }
    for(int i = 0; i < N; i++)
        if(isInCorrectPlace(records[i], i))
            sorted[i] = true;
    for(int i = 0; i < N - 1; i++){
        if(sorted[i])
            continue;
        for(int j = i + 1; j < N; j++){
            if(sorted[j])
                continue;
            if(isInCorrectPlace(records[i], j) && isInCorrectPlace(records[j], i)){
                ops++;
                int tmp1 = records[i];
                records[i] = records[j];
                records[j] = tmp1;
                sorted[i] = true;
                sorted[j] = true;
            }
        }
    }
    for(int i = 0; i < N - 1; i++){
        if(sorted[i])
            continue;
        for(int j = i + 1; j < N; j++){
            if(sorted[j] || sorted[i])
                continue;
            if(isInCorrectPlace(records[i], j) && isInCorrectPlace(records[j], i)){
                ops++;
                int tmp1 = records[i];
                records[i] = records[j];
                records[j] = tmp1;
                sorted[i] = true;
                sorted[j] = true;
            }
            else if(isInCorrectPlace(records[i], j) ^ isInCorrectPlace(records[j], i)){
                ops++;
                int tmp1 = records[i];
                records[i] = records[j];
                records[j] = tmp1;
                if(isInCorrectPlace(records[i], i))
                    sorted[i] = true;
                if(isInCorrectPlace(records[j], j))
                    sorted[j] = true;
            }
        }
    }
    fout << ops << endl;
    return 0;
}
