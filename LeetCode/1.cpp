class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> o;
        l1:for(int i = 0; i< nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    o.push_back(i);
                    o.push_back(j);
                    goto ret;
                }
            }
        }
        ret:
        return o;
    }
};