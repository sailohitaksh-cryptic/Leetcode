class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        sort(indexedNums.begin(), indexedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        int left = 0;
        int right = indexedNums.size() - 1;

        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;

            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {}; // No solution found
    }
};
