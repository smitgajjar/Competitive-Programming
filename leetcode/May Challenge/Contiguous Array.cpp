int mp[100001];
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), sum=0, maxlen=0;
        memset(mp, -1, n);
        for(int i=0; i<n; i++)
        {
            sum+=(!nums[i])?(-1):(1);
            if(!sum) maxlen=i+1;
            if(mp[sum+n]==-1)
                mp[sum+n]=i;
            else if(i-mp[sum+n]>maxlen)
                maxlen=i-mp[sum+n];
                
        }
        return maxlen;
    }
};