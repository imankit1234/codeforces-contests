#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (abs(a - b) % 2 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }

    return 0;
}
