class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i=0,j=1,count=0;
        while(count<nums.size())
        {
            if(nums[count]>0)
            {
                ans[i]=nums[count];
                i=i+2;
            }
            else
            {
                ans[j]=nums[count];
                j=j+2;
            }
            count++;
        }
        return ans;
    }
};