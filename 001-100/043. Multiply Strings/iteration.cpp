#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";

        int finalIdx{0};
        vector<int> num1Vec(num1.begin(), num1.end());
        vector<int> mul(400);

        for (int &i: num1Vec) i -= '0';
        for (int j = num2.size() - 1; j >= 0; --j) {
            for (int i = num1.size() - 1; i >= 0; --i) {
                int mulIdx = 401 - num2.size() + j - num1.size() + i;
                mul[mulIdx] += (num2[j] - '0') * num1Vec[i];
            }
        }
        for (int i{399}; i >= 1; --i) {
            int next{mul[i] / 10};
            mul[i] = mul[i] % 10 + '0', mul[i - 1] += next;
            if (mul[i] != '0') finalIdx = i;
        }
        return string(mul.begin() + finalIdx, mul.end());
    }
};

int main() {
    Solution solution;
    string result = solution.multiply("0","0");
    cout << result;
    return 0;
}
