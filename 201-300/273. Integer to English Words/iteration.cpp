#include <iostream>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {

        if (num == 0) return "Zero";

        string ret = "";
        int &&bilBit{num / 1000000000}, &&milBit{(num / 1000000) % 1000},
                &&thouBit{(num / 1000) % 1000}, &&bit{num % 1000};

        if (bilBit) ret = threeDigit(bilBit) + " Billion";
        if (milBit) ret += threeDigit(milBit) + " Million";
        if (thouBit) ret += threeDigit(thouBit) + " Thousand";
        if (bit) ret += threeDigit(bit);

        return string{&ret[1], &ret[ret.size()]};
    }

    string threeDigit(int num) {
        if (!num) return "";
        string ret;
        int &&hundred{num / 100}, &&ten{(num / 10) % 10}, &&bit{num % 10};
        if (hundred) {
            if (hundred == 9) ret = " Nine Hundred";
            else if (hundred == 8) ret = " Eight Hundred";
            else if (hundred == 7) ret = " Seven Hundred";
            else if (hundred == 6) ret = " Six Hundred";
            else if (hundred == 5) ret = " Five Hundred";
            else if (hundred == 4) ret = " Four Hundred";
            else if (hundred == 3) ret = " Three Hundred";
            else if (hundred == 2) ret = " Two Hundred";
            else ret = " One Hundred";
        }
        if (ten) {
            if (ten == 9) ret += " Ninety";
            else if (ten == 8) ret += " Eighty";
            else if (ten == 7) ret += " Seventy";
            else if (ten == 6) ret += " Sixty";
            else if (ten == 5) ret += " Fifty";
            else if (ten == 4) ret += " Forty";
            else if (ten == 3) ret += " Thirty";
            else if (ten == 2) ret += " Twenty";
            else {
                if (bit == 9) ret += " Nineteen";
                else if (bit == 8) ret += " Eighteen";
                else if (bit == 7) ret += " Seventeen";
                else if (bit == 6) ret += " Sixteen";
                else if (bit == 5) ret += " Fifteen";
                else if (bit == 4) ret += " Fourteen";
                else if (bit == 3) ret += " Thirteen";
                else if (bit == 2) ret += " Twelve";
                else if (bit == 1) ret += " Eleven";
                else ret += " Ten";
            }
        }
        if (ten != 1 && bit) {
            if (bit == 9) ret += " Nine";
            else if (bit == 8) ret += " Eight";
            else if (bit == 7) ret += " Seven";
            else if (bit == 6) ret += " Six";
            else if (bit == 5) ret += " Five";
            else if (bit == 4) ret += " Four";
            else if (bit == 3) ret += " Three";
            else if (bit == 2) ret += " Two";
            else ret += " One";
        }
        return ret;
    }
};

int main() {
    Solution solution;
    cout << solution.numberToWords(214748364);
    return 0;
}
