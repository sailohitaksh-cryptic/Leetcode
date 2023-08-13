class Solution {
public:
string longestPalindrome(string s) {
    int ls = s.length();
    int lm = ((ls + 2) << 1) - 1;
    string ms(lm + 5, '#');
    vector<int> ma(lm + 5, 0);
    ms[0] = '^';
    for (int i = 1; i <= ls; ++i) {
        ms[i << 1] = s[i - 1];
    }
    ms[lm - 1] = '$';

    int id = 0, mx = 0;
    for (int i = 1; i < lm; ++i) {
        int j = mx > i ? min(mx - i, ma[(id << 1) - i]) : 0;
        while (ms[i + j] == ms[i - j]) {
            ++j;
        }
        ma[i] = --j;
        if (i + j > mx) {
            mx = i + j;
            id = i;
        }
    }

    int x = 0, b = -1;
    for (int i = 0; i < lm; ++i) {
        if (x >= ma[i]) {
            continue;
        }
        x = ma[i];
        b = i - ma[i];
    }
    int bb = ((b + 1) >> 1) - 1;

    return s.substr(bb, x);
}
};