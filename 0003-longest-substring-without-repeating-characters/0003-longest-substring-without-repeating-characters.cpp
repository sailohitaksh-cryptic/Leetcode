class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    int i = 0, j = 0;

    std::unordered_set<char> uniqueChars;

    while (i < n && j < n) {
        if (uniqueChars.find(s[j]) == uniqueChars.end()) {
            uniqueChars.insert(s[j]);
            maxLength = std::max(maxLength, j - i + 1);
            j++;
        } else {
            uniqueChars.erase(s[i]);
            i++;
        }
    }

    return maxLength;
    }
};