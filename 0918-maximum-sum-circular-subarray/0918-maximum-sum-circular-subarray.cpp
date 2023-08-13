class Solution {
public:
    int normalsum(vector<int> nums)
    {
        int res=nums[0];
        int maxe=nums[0];
        for(int i =1;i<nums.size();i++)
        {
            maxe= max(nums[i],maxe+nums[i]);
            res= max(res,maxe);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxn = normalsum(nums);
        if(maxn<0)
            return maxn;
        int arr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            arr_sum+=nums[i];
            nums[i]=-nums[i];
        }
        int maxc=arr_sum+normalsum(nums);
        return max(maxc,maxn);
    }
};