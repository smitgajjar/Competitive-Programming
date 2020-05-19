class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        // unordered_map<string, bool> m;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++) {
                if(__gcd(i, j)==1 or i==1)
                    ans.emplace_back(to_string(i)+"/"+to_string(j));
            }
        }
        return ans;
    }
};