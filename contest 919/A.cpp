#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        long long a = 0, b = LLONG_MAX;
        int n;
        cin >> n;

        set<long long> s;

        while (n--) {
            int type;
            cin >> type;
            long long x;
            cin >> x;

            if (type == 1) {
                a = max(a, x);
            } else if (type == 2) {
                b = min(b, x);
            } else {
                s.insert(x);
            }
        }

        long long count = b - a + 1;

        for (auto x : s) {
            if (x >= a && x <= b) {
                count--;
            }
        }

        if (count < 0) {
            count = 0;
        }

        cout << count << endl;
    }

    return 0;
}
