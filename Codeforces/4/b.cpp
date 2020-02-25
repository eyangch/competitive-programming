#include <bits/stdc++.h>

using namespace std;

int main(){
    int D, sumTime;
    cin >> D >> sumTime;
    pair<int, int> study[D];
    for(int i = 0; i < D; i++){
        cin >> study[i].first >> study[i].second;
    }
    int studymin = 0, studymax = 0;
    for(int i = 0; i < D; i++){
        studymin += study[i].first;
        studymax += study[i].second;
    }
    if(studymin > sumTime || studymax < sumTime){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int diff = sumTime - studymin, day = 0;
    while(diff > 0){
        int tmp = study[day].first;
        study[day].first += min(study[day].second - tmp, diff);
        diff -= min(study[day].second - tmp, diff);
        day++;
    }
    for(int i = 0; i < D-1; i++){
        cout << study[i].first << " ";
    }
    cout << study[D-1].first << endl;
    return 0;
}
