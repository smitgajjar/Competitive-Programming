class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        int n=strs.size();
        string t;
        for(int i=0; i<n; i++)
        {
            t=strs[i];
            sort(t.begin(), t.end());
            m[t].push_back(strs[i]);
        }
        vector<vector<string>> ans(m.size());
        int k=0;
        for(auto i: m)
        {
            ans[k++]=i.second;
        }
        return ans;
    }
};