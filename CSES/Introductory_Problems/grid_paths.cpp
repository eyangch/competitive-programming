#include <bits/stdc++.h>
 
using namespace std;
 
char s[49];
int dx[128], dy[128];
long long vis;
int ans = 0;
char ar[5] = {'L', 'U', 'R', 'D', 'L'};
 
bool invalid(int x, int y){
    return (x < 0 || y < 0 || x >= 7 || y >= 7 || vis&(1LL<<(x+7*y)));
}
 
int deadend(int x, int y){
    if(invalid(x, y)) return 1;
    if(((invalid(x+dx['R'], y) & invalid(x+dx['L'], y)) ^ (invalid(x, y+dy['U']) & invalid(x, y+dy['D']))) &
            ((invalid(x+dx['R'], y) | invalid(x+dx['L'], y)) ^ (invalid(x, y+dy['U']) | invalid(x, y+dy['D'])))){
        return 1;
    }
    for(int i = 1; i < 4; i+=2){
        if(invalid(x, y+dy[ar[i]]) && invalid(x+dx[ar[i-1]], y+dy[ar[i-1]]) && !invalid(x+dx[ar[i-1]], y+dy[ar[i]])){
            return 1;
        }
    }
    for(int i = 2; i < 5; i+=2){
        if(invalid(x+dx[ar[i]], y) && invalid(x+dx[ar[i-1]], y+dy[ar[i-1]]) && !invalid(x+dx[ar[i]], y+dy[ar[i-1]])){
            return 1;
        }
    }
    return 0;
}
 
void dfs(int x, int y, int d){
    if(x == 0 && y == 6){
        if(d == 48){
            ans++;
        }
        return;
    }
    int clet = s[d];
    vis |= (1LL<<(x+7*y));
    if(clet == '?'){
        for(int i = 0; i < 4; i++){
            if(!deadend(x+dx[ar[i]], y+dy[ar[i]])){
                dfs(x+dx[ar[i]], y+dy[ar[i]], d+1);    
            }
        }
    }else{
        if(!deadend(x+dx[clet], y+dy[clet])){
            dfs(x+dx[clet], y+dy[clet], d+1);
        }
    }
    vis &= ~(1LL<<(x+7*y));
}
 
signed main(){
    dx['R'] = dy['D'] = 1;
    dx['L'] = dy['U'] = -1;
    dx['N'] = dx['S'] = dy['R'] = dy['L'] = 0;
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << endl;
}
