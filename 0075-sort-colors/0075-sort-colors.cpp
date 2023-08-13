class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red =0;
        int white=0;
        int blue = nums.size()-1;
        while(white<=blue)
        {
            if(nums[white]==0)
            {
                swap(nums[red],nums[white]);
                white++;
                red++;
            }
            else if(nums[white]==1)
                white++;
            else
            {
                swap(nums[blue],nums[white]);
                blue--;
            }
        }
        
    }
};