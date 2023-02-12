#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    char *numChar;
    int size{0};
public:
    int maximumSwap(int num) {

        int ret{0};
        priority_queue<pair<char, int>> q;

        numToChar(num);
        for (int i{0}; i < size; ++i) q.emplace(numChar[i], i);

        for (int i{0}; i < size; ++i) {
            while (q.top().second < i) q.pop();
            if (numChar[i] < q.top().first) {
                swap(numChar[i], numChar[q.top().second]);
                break;
            }
            if (q.top().second == i) q.pop();
        }
        for (int i{0}; i < size; ++i) {
            ret = ret * 10 + numChar[i];
        }

        return ret;
    }

    void numToChar(int num) {
        int temp{num};
        while (temp) {
            temp /= 10;
            ++size;
        }
        numChar = (char *) malloc(sizeof(char) * size);
        for (int i{1}; i <= size; ++i) {
            numChar[size - i] = num % 10;
            num /= 10;
        }
    }
};

int main() {
    Solution solution;
    int result = solution.maximumSwap(9973);
    cout << result;
    return 0;
}
