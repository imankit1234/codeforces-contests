#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

vector<long long> a(N), b(N), c(N), d(N);
vector<bitset<N>> bs(N);

template <typename T>
void print(const T &x) {
    cout << x << '\n';
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) cin >> c[i];

    auto solve = [&]() {
        for (int i = 0; i <= n; i++) bs[i].reset();
        sort(a.begin() + 1, a.begin() + n + 1);
        bs[0][0] = 1;
        bool fl = 0;
        for (int i = 1; i < n; i++)
            for (int j = q; j >= a[i]; j--)
                bs[j] |= (bs[j - a[i]] << a[i]) | bs[j - a[i]];

        for (int i = a[n]; i <= q - a[n]; i++) fl |= bs[q][i];
        for (int i = a[n - 1]; i <= q - a[n]; i++) fl |= bs[q - a[n]][i];
        return fl;
    };

    print(solve());

    while (q--) {
        int p, x, y, z;
        cin >> p >> x >> y >> z;
        a[p] = x;
        b[p] = y;
        if (p < n) c[p] = z;
        print(solve());
    }

    return 0;
}
