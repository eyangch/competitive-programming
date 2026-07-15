class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int N = players.size(), M = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        int t = 0;
        for(int i = 0; i < N; i++){
            while(t < M && trainers[t] < players[i]) t++;
            if(t < M){
                ans++;
                t++;
            }
        }
        return ans;
    }
};