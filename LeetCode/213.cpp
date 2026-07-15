class Solution {
public:
    int dp[100][2];
    int sim_rob(int N, vector<int> &nums){
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < N; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return dp[N-1][0];
    }
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1){
            return nums[0];
        }
        int ans = sim_rob(N, nums);
        rotate(nums.begin(), nums.begin()+1, nums.end());
        ans = max(ans, sim_rob(N, nums));
        return ans;
    }
};