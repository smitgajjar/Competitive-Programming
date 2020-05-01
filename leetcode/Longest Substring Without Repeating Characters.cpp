class Solution {
    
public:
    Solution()
    {
        ios_base::sync_with_stdio(false), cin.tie(NULL);
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int j=0, i=0, ans=0;
        unordered_map<char, int> a;
        while(i<n and j<n)
        {
            if(a[s[j]])
            {
                a[s[i]]=0;
                i++;
            }
            else
            {
                a[s[j]]=1;
                j++;
                ans=max(ans, j-i);
            }
        }
        return ans;
    }
};