class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0}, m=s1.length(), n=s2.length();
        for(auto i: s1)
            freq[i-'a']++;
        int i, j;
        i=j=0;
        while(j<n)
        {
            if(freq[s2[j]-'a']>0)
            {
                freq[s2[j]-'a']--;
                j++;
                if(j-i==m)
                    return true;
            }
            else if(i==j)
            {
                i++, j++;
            }
            else
            {
                freq[s2[i]-'a']++;
                i++;
            }
        }
        return false;
    }
};