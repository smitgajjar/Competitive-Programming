class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=nums[0], sum=nums[0];
        for(int i=1; i<n; i++)
        {
            sum=max(sum+nums[i], nums[i]);
            ans=max(ans, sum);
        }
        return ans;
    }
};