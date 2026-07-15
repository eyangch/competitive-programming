class Solution {
public:
    int N;
    long long cnt[3001];
    long long dividePlayers(vector<int>& skill) {
        N = skill.size();
        //fill(cnt, cnt+1001, 0);
        long long sum = 0;
        for(int i = 0; i < N; i++){
            sum += skill[i];
            cnt[skill[i]]++;
        }
        if(sum % (N/2) != 0) return -1;
        sum /= (N/2);
        long long ans = 0;
        for(long long i = 0; i < sum/2 + sum%2; i++){
            long long j = sum-i;
            //cout << i << ' ' << j << ' ' << cnt[i] << ' ' << cnt[j] << endl;
            if(cnt[i] != cnt[j]) return -1;
            ans += i * j * cnt[i];
        }
        if(sum % 2 == 0){
            long long x = sum / 2;
            if(cnt[x] % 2) return -1;
            ans += x * x * cnt[x]/2;
        }
        return ans;
    }
};