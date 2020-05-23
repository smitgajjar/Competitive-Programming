class Solution {
public:
    string frequencySort(string s) {
        // unordered_map<char, int> um;
        int um[128]={0};
        multimap<int, char>mm;
        for(char c: s)
            um[c]++;
        for(int i=0; i<128; i++)
        {
            if(um[i])
                // mm.insert({p.second,p.first});
                mm.insert({um[i], i});
        }
        string ans="";
        for(auto p=mm.rbegin(); p!=mm.rend(); p++)
            ans+=string(p->first, p->second);
        return ans;       
    }
};