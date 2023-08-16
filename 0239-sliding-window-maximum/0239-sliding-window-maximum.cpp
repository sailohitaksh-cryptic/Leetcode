class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    if (k == 0) return result;
    deque<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        // If the pq head in out of the window --> pop head
        while (!w.empty() && w.front() <= i-k)
            w.pop_front();
        // If mq is non empty and current val >= last element of mq
        // --> remove all elements that are <= from back 
        while (!w.empty() && nums[w.back()] <= nums[i])
            w.pop_back();
        // Takes care of inserting into the end
        w.push_back(i);
        // Store results from the end of the first window
        if (i >= k-1)
            result.push_back(nums[w.front()]);
    }
    return result;
        
    }
};