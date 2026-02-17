#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────
// Brute Force  →  O(n * min(a,b))
// ─────────────────────────────────────────
class SolutionBrute {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9 + 7;
        long long count = 0;
        long long num = 1;

        while (count < n) {
            if (num % a == 0 || num % b == 0)
                count++;
            num++;
        }

        return (num - 1) % mod;
    }
};

// ─────────────────────────────────────────
// Optimal  →  O(log(n * min(a,b)))
// ─────────────────────────────────────────
class SolutionOptimal {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9 + 7;

        long long g   = gcd(a, b);
        long long lcm = (1LL * a * b) / g;

        long long low = 1;
        long long high = 1LL * n * min(a, b);
        long long ans  = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // how many magical numbers exist in [1, mid]?
            long long cnt = mid / a + mid / b - mid / lcm;

            if (cnt >= n) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % mod;
    }
};

// ─────────────────────────────────────────
// Helper: run both and compare
// ─────────────────────────────────────────
void solve(int n, int a, int b) {
    SolutionBrute   brute;
    SolutionOptimal optimal;

    int r1 = brute.nthMagicalNumber(n, a, b);
    int r2 = optimal.nthMagicalNumber(n, a, b);

    cout << "n=" << n << "  a=" << a << "  b=" << b << "\n";
    cout << "  Brute   : " << r1 << "\n";
    cout << "  Optimal : " << r2 << "\n";
    cout << "  Match   : " << (r1 == r2 ? "YES" : "NO") << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ── preset test cases ──────────────────
    cout << "===== Preset Test Cases =====\n\n";
    solve(1,  2,  3);   // expected: 2
    solve(4,  2,  3);   // expected: 6
    solve(5,  2,  4);   // expected: 10
    solve(3,  6,  4);   // expected: 8
    solve(10, 3,  5);   // expected: 15

    // ── custom input ──────────────────────
    cout << "===== Custom Input =====\n";
    cout << "Enter n, a, b: ";
    int n, a, b;
    cin >> n >> a >> b;
    solve(n, a, b);

    return 0;
}
