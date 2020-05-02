class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) {
            return 0;
        }
        
        vector<unsigned long long> dp(target+1);
        dp[0]=1;
        for(int i=1; i<=target; i++) {
            dp[i]=0;
            for(int j=0; j<n; j++) {
                if(i-nums[j]>=0) {
                    dp[i]+=(unsigned long long)dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};