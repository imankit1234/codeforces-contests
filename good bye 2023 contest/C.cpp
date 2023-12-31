#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define sz(x) (int)(x).size()
#define pb push_back

ll lcm(ll a, ll b) {
    ll c = (a * b) / (__gcd(a, b));
    return c;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> arr(n);

    rep(i, n) {
        cin >> arr[i];
    }

    ll sum = 0;
    vector<ll> ans;
    ll even = 0, odd = 0;

    rep(i, n) {
        sum += arr[i];

        if (arr[i] & 1) {
            odd++;
        } else {
            even++;
        }

        if (i == 0) {
            ans.pb(arr[0]);
            continue;
        }

        ll comp = odd / 3;
        ll left = odd % 3;

        ll c = comp;

        if (left == 1) {
            c += 1;
        }
        ans.pb(sum - c);
    }

    rep(i, sz(ans)) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
