class Solution {
public:
    int firstUniqChar(string s) {
        int mp[26]={0}, n=s.length();
        for(char c: s)
            mp[c-'a']++;
        for(int i=0; i<n; i++)
        {
            if(mp[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};