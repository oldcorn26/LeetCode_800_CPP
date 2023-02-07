#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int size = flowerbed.size();
        for (int i{0}; i < size; ++i) {
            if (flowerbed[i] == 0 && (i == size - 1 || flowerbed[i + 1] == 0)) {
                --n, ++i;
            } else if (flowerbed[i] == 1) ++i;
        }
        return n <= 0;
    }
};

int main() {
    Solution solution;
    vector<int> flowerbed{1,0,0,0,1};
    bool result = solution.canPlaceFlowers(flowerbed, 1);
    cout << result;
    return 0;
}
