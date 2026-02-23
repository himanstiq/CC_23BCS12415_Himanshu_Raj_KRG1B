#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool is_strictly_inside(const vector<Point>& A, Point p) {
    int n = A.size();
    
    if (cross_product(A[0], A[1], p) >= 0) return false;
    
    if (cross_product(A[n-1], A[0], p) >= 0) return false;
    
    int l = 1, r = n - 2;
    int idx = -1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cross_product(A[0], A[mid], p) < 0) {
            idx = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    if (idx == -1) return false;
    
    if (cross_product(A[idx], A[idx+1], p) >= 0) return false;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<Point> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
    }
    
    int m;
    cin >> m;
    vector<Point> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i].x >> B[i].y;
    }
    
    for (int i = 0; i < m; ++i) {
        if (!is_strictly_inside(A, B[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
