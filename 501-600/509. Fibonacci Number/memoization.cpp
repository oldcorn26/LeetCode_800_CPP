#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo{0, 1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
public:
    int fib(int n) {
        if (memo[n] != -1) return memo[n];
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution solution;
    int result = solution.fib(20);
    cout << result;
    return 0;
}
