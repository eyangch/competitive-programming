class Solution {
public:
    int getDist(vector<int> p1, vector<int> p2, int r){
        int x = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
        if(x == 0)
            return r;
        return x;
    }
    bool rightAngle(vector<int> p1, vector<int> p, vector<int> p2){
        if(p1[0] == p[0]){
            if(p2[1] == p[1])
                return true;
            else
                return false;
        }
        if(p2[0] == p[0]){
            if(p1[1] == p[1])
                return true;
            else
                return false;
        }
        float slope1 = (p1[1] - p[1])/((float)p1[0] - (float)p[0]);
        float slope2 = (p2[1] - p[1])/((float)p2[0] - (float)p[0]);
        if(slope2 == 0)
            return false;
        if(abs(slope1 + (1/slope2)) < 0.00001f)
            return true;
        else
            return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        sort(points.begin(), points.end());
        if(getDist(points[0], points[1], 0) == getDist(points[1], points[3], 1) &&
          getDist(points[3], points[2], 2) == getDist(points[2], points[0], 3))
            if(rightAngle(points[0], points[1], points[3]) &&
              rightAngle(points[0], points[2], points[3]))
                return true;
        return false;
    }
};