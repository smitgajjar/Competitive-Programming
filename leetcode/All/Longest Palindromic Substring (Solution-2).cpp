// There are n centers which will result in odd length palindromes
// and n-1 centers which will result in even length palindromes.
// Total centers =2n-1
// So, just expand around center!

// T: O(n2), M: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return s;
        pair<int, int>  p={0, 0};
        
        int i, j, maxlen;
        // find odd length palindromes (around 1 center)
        for(int c=0; c<n; c++)
        {
            i=j=c;
            while(i>=0 and j<n and s[i]==s[j])
            {
                i--; j++;
            }
            i++;
            j--;
            if(j-i+1>maxlen)
            {
                maxlen=j-i+1;
                p={i, j};
            }
        }
        // find even length palindromes (around 2 centers)
        for(int c=0; c<n-1; c++)
        {
            i=c;
            j=c+1;
            while(i>=0 and j<n and s[i]==s[j])
            {
                i--; j++;
            }
            i++;
            j--;
            if(j-i+1>maxlen)
            {
                maxlen=j-i+1;
                p={i, j};
            }
        }
        return s.substr(p.first, p.second-p.first+1);
        
    }
};