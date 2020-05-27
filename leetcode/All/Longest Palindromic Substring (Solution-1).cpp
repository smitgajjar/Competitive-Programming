// DP solution
// dp array stores whether a substring starting with i
// and ending with j is a palindromme or not

// It is then easier to find the longest using this formula
// dp[i, i] = 1
// dp[i, j] = s[i]==s[j] and dp[i+1, j-1]
// T: O(n2), M: O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        pair<int, int>  p={0, 0};
        int i, j, k, maxlen=1;
        i=j=k=0;
        while(k<n)
        {
            for(; j<n; j++, i++)
            {
                if(i==j)
                    dp[i][j]=1;
                else if(k==1 and s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k+1>maxlen)
                    {
                        maxlen=k+1;
                        p={i,j};
                    }
                }
                else if(s[i]==s[j] and dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(k+1>maxlen)
                    {
                        maxlen=k+1;
                        p={i,j};
                    }
                }
            }
            k++;
            i=0;
            j=k;
        }
        return s.substr(p.first, p.second-p.first+1);
    }
};