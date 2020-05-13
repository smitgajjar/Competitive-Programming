class Solution {
public:
    
    int getAns(vector<int> nums, int l, int r) {
        int len=(r-l+1);
        int mid=l+(len+1)/2-1;
        if((((len+1)/2)&1)==1)
        {
            if(nums[mid+1]==nums[mid])
                return getAns(nums, mid+2, r);
            if(nums[mid-1]==nums[mid])
                return getAns(nums, l, mid-2);
        }
        else
        {
            if(nums[mid-1]==nums[mid])
                return getAns(nums, mid+1, r);
            if(nums[mid+1]==nums[mid])
                return getAns(nums, l, mid-1);
        }
        return nums[mid];
    }
        
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        return getAns(nums, 0, n-1);
    }
};