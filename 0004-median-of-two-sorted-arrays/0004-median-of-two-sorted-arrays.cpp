class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int partition = (n + 1) / 2;
    int start = 0, end = n1;

    while (start <= end) {
        int mid1 = start + (end - start) / 2;
        int mid2 = partition - mid1;

        int leftA = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int leftB = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int rightA = (mid1 < n1) ? nums1[mid1] : INT_MAX;
        int rightB = (mid2 < n2) ? nums2[mid2] : INT_MAX;

        if (leftA <= rightB && leftB <= rightA) {
            if (n % 2 == 0) {
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            } else {
                return max(leftA, leftB);
            }
        } else if (leftA > rightB) {
            end = mid1 - 1;
        } else {
            start = mid1 + 1;
        }
    }

    return 0.0;
        
    }
};