#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define per(i, n) for (int i = (n)-1; 0 <= i; i--)
#define rep2(i, l, r) for (int i = (l); i < int(r); i++)
#define per2(i, l, r) for (int i = (r)-1; int(1) <= i; i--)
#define each(e, v) for (auto &e : v)
#define MM << '\n' <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty())
        cout << '\n';
}

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

const int inf = 1e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        a[0] = inf;
        rep2(i, 1, n + 1) cin >> a[i];
        int m0 = inf, m1 = inf, ans = 0;
        rep(i, n) {
            int nans = inf, nm0 = 1, nm1 = -1;
            int now = a[i + 1], prev = a[i];
            auto upd = [&](int val, int m) { // Added '&' and a proper lambda
                if (chmin(nans, val))
                    nm0 = m;
                else if (nans == val)
                    chmax(nm0, m);
                else if (nans + 1 == val)
                    chmax(nm1, m);
            };
            upd(ans + (now > m0), prev);
            upd(ans + 1 + (now > prev), m1);
            upd(ans + 1 + (now > m1), prev);
            upd(ans + (now > prev), m0);
            swap(ans, nans);
            swap(m0, nm0);
            swap(m1, nm1);
        }
        cout << ans << '\n';
    }
    return 0;
}
