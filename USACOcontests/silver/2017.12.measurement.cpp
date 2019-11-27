#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <utility>
#include <array>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    set<array<int, 3>> m;
    unordered_map<int, int> ids;
    array<int, 100000> milkvalues;
    int N, G;
    fin >> N >> G;
    for(int i = 0; i < N; i++){
        array<int, 3> tmp;
        fin >> tmp[0] >> tmp[1] >> tmp[2];
        m.insert(tmp);
        ids.insert(make_pair(tmp[1], ids.size())); // Convert raw input id to scaled ID (ALWAYS USE SCALED ID)
    }
    fill(milkvalues.begin(), milkvalues.begin() + N, G);
    set<pair<int, int>> milkvalsorted;
    set<int> topcows;
    for(unsigned int i = 0; i < ids.size(); i++){
        milkvalsorted.insert(make_pair(G, i)); //init sorted values
        topcows.insert(i);
    }
    int maxmilk = G;
    int changes = 0;
    for(set<array<int, 3>>::iterator it = m.begin(); it != m.end(); it++){
        array<int, 3> today = *it;
        int scaledID = ids[today[1]];
        milkvalsorted.erase(make_pair(milkvalues[scaledID], scaledID));
        milkvalues[scaledID] += today[2];
        milkvalsorted.insert(make_pair(milkvalues[scaledID], scaledID));
        if(milkvalues[scaledID] > maxmilk){
            if(topcows.size() != 1 || topcows.find(scaledID) == topcows.end() || maxmilk == G){
                changes++;
                topcows.clear();
                topcows.insert(scaledID);
            }
            maxmilk = milkvalues[scaledID];
        }else if(milkvalues[scaledID] == maxmilk){
            changes++;
            topcows.insert(scaledID);
        }else if(milkvalues[scaledID] < maxmilk && topcows.find(scaledID) != topcows.end()){
            if(topcows.size() > 1){
                topcows.erase(scaledID);
                changes++;
            }else{
                topcows.clear();
                int m = get<0>(*milkvalsorted.rbegin());
                set<pair<int, int>>::reverse_iterator l = milkvalsorted.rbegin();
                int newcows = 0;
                while(get<0>(*l) == m && l != milkvalsorted.rend()){
                    newcows++;
                    topcows.insert(get<1>(*l));
                    l++;
                }
                l--;
                if(newcows > 1 || get<1>(*l) != scaledID)
                    changes++;
                maxmilk = m;
            }
        }
    }
    fout << changes << endl;
    return 0;
}
