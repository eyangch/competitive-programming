class Solution {
public:
    vector<vector<int>> addToZero(vector<int> use, int target){
        vector<vector<int>> ret;
        int a = 0;
        int z = use.size() - 1;
        while(a < z){
            int t = use[a] + use[z];
            if(t == target){
                vector<int> r1;
                r1.push_back(use[a]);
                r1.push_back(use[z]);
                ret.push_back(r1);
                a++;
                z--;
            }else if(t < target){
                a++;
            }else{
                z--;
            }
        }
        return ret;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> aaaaaa;
        if(nums.size() >= 3 && std::equal(nums.begin() + 1, nums.end(), nums.begin())){
            vector<int> ret;
            if(nums[0] == 0){
                for(int i = 0; i < 3; i++) ret.push_back(0);
                aaaaaa.push_back(ret);
            }
            return aaaaaa;
        }else if(nums.size() < 3){
            return aaaaaa;
        }
        set<vector<int>> ret;
        unordered_map<int, int> addZero;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            addZero.insert(make_pair(nums[i], 0 - nums[i]));
        }
        for(int i = 0; i < nums.size(); i++){
            vector<int> use = nums;
            use.erase(use.begin() + i);
            vector<vector<int>> r = addToZero(use, addZero.find(nums[i])-> second);
            for(int j = 0; j < r.size(); j++){
                vector<int> tr;
                tr = r[j];
                tr.push_back(nums[i]);
                sort(tr.begin(), tr.end());
                ret.insert(tr);
            }
        }
        vector<vector<int>> retvec(ret.size());
        int itint = 0;
        for(set<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++){
             retvec[itint].assign((*it).begin(), (*it).end());
            itint++;
        }
       
        return retvec;
    }
};