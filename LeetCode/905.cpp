class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> e;
        vector<int> o;
        for(int i = 0; i < A.size(); i++)
            (A[i] % 2 == 0) ? (e.push_back(A[i])) : (o.push_back(A[i]));
        e.insert(e.end(), o.begin(), o.end());
        return e;
    }
};