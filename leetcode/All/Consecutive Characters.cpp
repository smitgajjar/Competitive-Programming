class Solution {
public:
    int maxPower(string s) {
        int maxx=1, curr=s[0], cnt=1, n=s.length();
        for(int i=1; i<n; i++)
        {
            if(curr==s[i])
            {
                cnt++;
            }
            else
            {
                maxx=max(maxx, cnt);
                cnt=1;
                curr=s[i];
            }
        }
        maxx=max(maxx, cnt);
        return maxx;
            
        
    }
};