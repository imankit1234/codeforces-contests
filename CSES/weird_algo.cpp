#include <iostream>
#include <unordered_map>

std::unordered_map<long long, bool> memo;

bool isEven(long long n) {
    return n % 2 == 0;
}

long long nextNumber(long long n) {
    return isEven(n) ? n / 2 : 3 * n + 1;
}

void simulateAlgorithm(long long n) {
    while (n != 1) {
        std::cout << n << " ";

        // Check if the result is already memoized
        if (memo.find(n) != memo.end()) {
            std::cout << " (repeating sequence) ";
            break;
        }

        memo[n] = true;

        n = nextNumber(n);
    }

    std::cout << 1 << std::endl;
}

int main() {
    long long n;
    std::cin >> n;

    simulateAlgorithm(n);

    return 0;
}
