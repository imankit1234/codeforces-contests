#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool isCompleteBinaryTree(vector<int>& a) {
    int n = a.size();
    
    // Sort the array in ascending order
    sort(a.begin(), a.end());

    // Iterate through the array and check if it satisfies the conditions
    for (int i = 0; i < n; ++i) {
        if (a[i] > i) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << isCompleteBinaryTree(a) << endl;
    }

    return 0;
}
