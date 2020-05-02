class Solution {
public:
    string getSquareSum(string s) {
        int ans = 0;
        for(char c: s)
        {
            ans+=(c-'0')*(c-'0');
        }
        string st = to_string(ans);
        sort(st.begin(), st.end());
        int i=0;
        while(st[i]=='0')
            i++;
        st.erase(0, i);
        return st;
    }
    
    bool isHappy(int n) {
        unordered_map<string, int> m;
        string s=getSquareSum(to_string(n));
        m[s]=1;
        bool flag=1;
        while(s!="1")
        {
            s=getSquareSum(s);
            if(m[s]==1)
            {
                flag=0;
                break;
            }
            m[s]=1;
        }
        return flag;
    }
};