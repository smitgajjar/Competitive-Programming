class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp="";
        for(int j=0; j<digits.length(); j++)
        {
            do
            {
                if(ans.size()!=0)
                {
                    temp=ans.front();
                    ans.erase(ans.begin());
                }
                for(int i=0; i<mp[digits[j]-'0'].length(); i++)
                    ans.push_back(temp+mp[digits[j]-'0'][i]);
            }
            while((ans.front()).length()!=(j+1));
        }
        return ans;
    }
};