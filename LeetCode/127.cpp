class Solution {
public:
    int G[5000][10];
    vector<int> C[50000];
    unordered_map<long long, int> mp;
    int c_num = 0;
    int dist[5000];
    long long hs(string s, int omit){
        long long ret = 0;
        long long mult = 1;
        for(int i = 0; i < s.length(); i++){
            if(i != omit){
                ret += (s[i]-'a') * mult;
                mult *= 26;
            }
        }
        return ret * 10 + omit;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int N = wordList.size();
        int target = -1;
        for(int i = 0; i < N; i++){
            if(wordList[i] == endWord){
                target = i;
                break;
            }
        }
        if(target == -1) return 0;
        for(int i = 0; i < beginWord.length(); i++){
            for(int j = 0; j < N; j++){
                long long h = hs(wordList[j], i);
                auto it = mp.find(h);
                int cc = c_num;
                if(it == mp.end()){
                    mp[h] = c_num++;
                }else{
                    cc = it->second;
                }
                G[j][i] = cc;
                C[cc].push_back(j);
            }
        }
        fill(dist, dist+N, 1e9);
        queue<int> bfs;
        bfs.push(N-1);
        dist[N-1] = 1;
        while(!bfs.empty()){
            int v = bfs.front();
            bfs.pop();
            for(int i = 0; i < beginWord.size(); i++){
                for(int c : C[G[v][i]]){
                    if(dist[c] > dist[v] + 1){
                        dist[c] = dist[v] + 1;
                        bfs.push(c);
                    }
                }
            }
        }
        if(dist[target] == 1e9) return 0;
        return dist[target];
    }
};