class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int i = 1;
        for(; i < A.size() - 1; i++)
            if(A[i] <= A[i-1])
                break;
        if(i == 1)
            return false;
        for(; i < A.size(); i++)
            if(A[i] >= A[i-1])
                return false;
        return true;
    }
};