class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int maxProfit(vector<int>& prices) {
        long long sum=0, n=prices.size();
        int buy=-1, sell=-1;
        for(int i=1; i<n; i++)
        {
            if(buy==-1)
            {
                if(prices[i]>prices[i-1])
                {
                    buy=i-1;
                    sell=i;
                }
            }
            else
            {
                if(prices[i]>prices[i-1])
                {
                    sell=i;
                }
                else if(prices[i]<prices[i-1])
                {
                    sum+=prices[sell]-prices[buy];
                    buy=-1;
                }
            }
            if(i==n-1 and buy!=-1 and sell!=-1)
            {
                sum+=prices[sell]-prices[buy];
            }
        }
        return sum;
        
    }
};