#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define ll long long


void solveTest() {
    ll n, k, x;
    cin >> n >> k >> x;
    ll a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    ll sum = 0;
    ll end = n - x;

    rep(i, n) {
        if (i < end) sum += a[i];
        else sum -= a[i];
    }

    ll ans = sum;

    for (ll i = n - 1; i >= n - k; i--) {
        if (i >= end) {
            sum += a[i];
            if (end - 1 >= 0) sum -= 2 * a[end - 1];
            end--;
            ans = max(sum, ans);
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    
    while (t--) {
        solveTest();
    }

    return 0;
}
