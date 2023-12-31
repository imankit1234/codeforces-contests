#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
   int a, b; cin >> a >> b;
   int ans = (a*b)/__gcd(a, b);
   if (ans == b) cout << ans*(b/a) << "\n";
   else cout << ans<<"\n";
}
signed main() 
{
    int testcase = 1;cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}