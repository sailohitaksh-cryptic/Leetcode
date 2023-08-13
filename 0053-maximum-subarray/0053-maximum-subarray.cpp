class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int maxend=nums[0];
        for(int i =1; i<nums.size();i++)
        {
            maxend=max(maxend+nums[i],nums[i]);
            res=max(maxend,res);
        }
        return res;
        
    }
};