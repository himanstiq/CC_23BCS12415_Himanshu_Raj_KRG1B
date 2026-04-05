class Solution1 {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> mp;
            int dup = 0;
            for (int j = i+1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) { dup++; continue; }
                int g = __gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0) { dx = -dx; dy = -dy; }
                mp[{dy, dx}]++;
            }
            int best = 0;
            for (auto& p : mp) best = max(best, p.second);
            ans = max(ans, best + dup + 1);
        }
        return ans;
    }
};
