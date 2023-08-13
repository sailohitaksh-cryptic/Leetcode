class Solution {
public:
    int myAtoi(string s) {
        // Remove leading whitespace
    size_t i = 0;
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    
    // Check if the string is empty
    if (i == s.length()) {
        return 0;
    }

    // Check if the number is negative or positive
    int sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    // Read digits until a non-digit character is encountered
    long long result = 0;
    while (i < s.length() && std::isdigit(s[i])) {
        result = result * 10 + (s[i++] - '0');
        
        // Check if the number is out of range
        if (result * sign < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        } else if (result * sign > std::numeric_limits<int>::max()) {
            return std::numeric_limits<int>::max();
        }
    }

    return static_cast<int>(result * sign);
    }
};