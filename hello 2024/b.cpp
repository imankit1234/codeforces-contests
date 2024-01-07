#include <iostream>
#define ll long long
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll x = 0, y = 0;
        for (auto i : s)  {
            if (i == '-') x++;
            else y++;
        }

        ll result = abs(x - y);
        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}