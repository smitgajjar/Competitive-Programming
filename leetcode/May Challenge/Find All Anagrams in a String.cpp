class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26]={0}, m=p.length(), n=s.length();
        vector<int> ans;
        for(auto i: p)
            freq[i-'a']++;
        int i, j;
        i=j=0;
        while(j<n)
        {
            if(freq[s[j]-'a']>0)
            {
                freq[s[j]-'a']--;
                j++;
                if(j-i==m)
                    ans.push_back(i);
            }
            else if(i==j)
            {
                i++, j++;
            }
            else
            {
                freq[s[i]-'a']++;
                i++;
            }
        }
        return ans;
    }
};