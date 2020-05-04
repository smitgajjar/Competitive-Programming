class Solution {
public:
    int mag[26], ran[26];
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool canConstruct(string ransomNote, string magazine) {
        memset(mag, 0, sizeof mag);
        memset(ran, 0, sizeof ran);
        for(char c: magazine)
            mag[c-'a']++;
        for(char c: ransomNote)
            ran[c-'a']++;
        for(int i=0; i<26; i++)
            if(ran[i]>mag[i])
                return false;
        return true;
    }
};