class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pivotIdx) {
        int pivotValue = nums[pivotIdx];
        swap(nums[pivotIdx], nums[right]); 
        int storeIdx = left;
        for (int i = left; i < right; i++) 
        {
            if (nums[i] < pivotValue) 
            {
                swap(nums[storeIdx], nums[i]);
                ++storeIdx;
            }
        }
        swap(nums[right], nums[storeIdx]);
        return storeIdx;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if (left == right) 
        {
            return nums[left];
        }
        int pivotIdx = left + std::rand() % (right - left + 1);
        pivotIdx = partition(nums, left, right, pivotIdx);
        if (k == pivotIdx) 
        {
            return nums[k];
        } 
        else if (k < pivotIdx) 
        {
            return quickSelect(nums, left, pivotIdx - 1, k);
        } 
        else 
        {
            return quickSelect(nums, pivotIdx + 1, right, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};