class Solution {
public:
    bool ok(vector<int> &nums, int k, int cap){
        int stolen = 0, p_stolen = 0;
        for(int i = 0; i < nums.size() && stolen < k; i++){
            if(nums[i] <= cap && !p_stolen){
                stolen++, p_stolen = 1;
            }else{
                p_stolen = 0;
            }
        }
        return stolen >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int lo = 0, hi = 1e9+5, mid = 0, ans = 0;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(ok(nums, k, mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};