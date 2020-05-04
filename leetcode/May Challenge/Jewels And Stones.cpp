class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> m;
        int cnt=0;
        for(char c: J)
            m[c]=true;
        for(char c: S)
            if(m[c])
                cnt++;
        return cnt;
    }
};