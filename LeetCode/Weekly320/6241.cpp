class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                for(int k = j+1; k < N; k++){
                    if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};