#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        if (text.empty())
            return 0;
        for (int i{1}, size = text.size(); i <= size / 2; ++i) // 枚举前后缀长度
            if (text.substr(0, i) == text.substr(size - i)) // 立刻分割
                return 2 + longestDecomposition(text.substr(i, size - i * 2));
        return 1; // 无法分割
    }
};

int main() {
    Solution solution;
    return 0;
}
