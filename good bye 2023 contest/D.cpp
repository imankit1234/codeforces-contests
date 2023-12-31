#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<long long> findSquares(int n) {
    vector<long long> squares;

    for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
        for (int lastDigit : {0, 1, 4, 5, 6, 9}) {
            int middleDigit = (n % 2 == 1) ? 1 : 0; // Odd middle digit for odd n
            long long number = firstDigit * pow(10, n - 1) + middleDigit * pow(10, (n - 1) / 2) + lastDigit;
            long long squareRoot = sqrt(number);
            if (squareRoot * squareRoot == number) {
                squares.push_back(number);
            }
        }
    }

    // Group squares by digit multisets
    unordered_map<vector<int>, vector<long long>> groupedSquares;
    for (long long square : squares) {
        vector<int> digits;
        long long tempSquare = square;  // Store a copy of square
        while (tempSquare) {
            digits.push_back(tempSquare % 10);
            tempSquare /= 10;
        }
        sort(digits.begin(), digits.end()); // Ensure consistent ordering for comparison
        groupedSquares[digits].push_back(square);
    }

    // Find the group with n squares and return its elements
    for (const auto& [digits, group] : groupedSquares) {
        if (group.size() == n) {
            return group;
        }
    }

    return {}; // No solution found
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> solution = findSquares(n);
        for (long long square : solution) {
            cout << square << endl;
        }
    }

    return 0;
}
