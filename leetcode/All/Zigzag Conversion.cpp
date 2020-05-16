class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<char> pat[numRows];
        int j=0, n=s.length();
        bool flag=1;
        for(int i=0; i<n; i++)
        {
            pat[j].push_back(s[i]);
            if(j==numRows-1 or (j==0 and i!=0))
                flag=!flag;
            if(flag)
                j++;
            else
                j--;
            // cout<<j<<endl;
            
        }
        string ans;
        for(auto i: pat)
            for(auto j: i)
                ans+=j;
        return ans;
    }
};