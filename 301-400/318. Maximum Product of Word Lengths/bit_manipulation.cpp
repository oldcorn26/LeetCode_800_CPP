#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        int ret{};
        vector<int> wordMask(size);
        for (int i{}; i < size; ++i)
            for (char &ch: words[i])
                wordMask[i] |= 1 << (ch - 'a');
        for (int i{}; i < size; ++i)
            for (int j{i+1}; j < size; ++j)
                if ((wordMask[i] & wordMask[j]) == 0)
                    ret = max(ret, static_cast<int>(words[i].size()*words[j].size()));
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
