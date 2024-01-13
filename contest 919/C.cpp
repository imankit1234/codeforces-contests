#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define all(x) x.begin(), x.end()

vector<int> divs;

void printDivisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                divs.push_back(i);
            } else {
                divs.push_back(i);
                divs.push_back(n / i);
            }
        }
    }
}

void get(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    get(arr, n);
    divs.clear();
    printDivisors(n);
    int ans = 1;

    for (int i = 0; i < divs.size(); i++) {
        if (divs[i] == n) {
            continue;
        }
        map<int, vector<int>> mp;
        for (int j = 1; j <= n; j++) {
            mp[j % divs[i]].push_back(arr[j - 1]);
        }
        int hue = 0;
        for (auto x : mp) {
            int pp = 0;
            sort(all(x.second));
            for (int i = 1; i < x.second.size(); i++) {
                pp = __gcd(pp, x.second[i] - x.second[i - 1]);
            }
            hue = __gcd(hue, pp);
        }
        if (hue != 1) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
